#include "SolverVolume.h"

namespace solver {

	SolverVolume::SolverVolume(problem::SingleItemLotSizing* problem){
		this->easy_problem = new solver::DynamicSolver(problem);
		this->problem = problem;

		unsigned int nb_periods = this->problem->getNbPeriods();
		unsigned int nb_items = this->problem->getNbItems();

		std::vector<double> sum_demand;
		for(unsigned int i=0; i<nb_items; i++){
			sum_demand.push_back(0);
		}

		matrix x;
		matrix y;
		matrix h;

		for(unsigned int t=0; t<nb_periods; t++){
			this->pi.push_back(0);
			this->pi_hat.push_back(0);
		}
		
		for (unsigned int i = 0; i < nb_items; ++i){
			std::vector<double> prod_item(nb_periods,0); 
			x.push_back(prod_item);
			y.push_back(prod_item);
			h.push_back(prod_item);

			//Définir demande
			for(unsigned int t=0; t<nb_periods; t++){
				sum_demand[i] += this->problem->getPeriodData(t,i,data::LSPeriod::DEMAND);
			}
		}

		//création solution 0
		double value = 0;
		for(unsigned int i=0; i<nb_items; i++){
			value += sum_demand[i] * this->problem->getPeriodData(i,i,data::LSPeriod::PRODUCTION_COST);
			x[i][i] = sum_demand[i];
			y[i][i] = 1;
		}

		this->UB = value;
		this->current_LB = 0; //Pour tester
		this->current_x = new problem::Solution(x,value);
		this->current_y = new problem::Solution(y,value);
		this->current_g = new problem::Solution(x,value);
		this->current_h = new problem::Solution(y,value);
		this->easy_problem->updatePi(this->pi);
 
	}

	SolverVolume::~SolverVolume(){
		/*for( auto b : this->bundle){
			delete b;
		}*/
		delete this->easy_problem;
		delete this->current_x;
		delete this->current_y;
		delete this->current_g;
		delete this->current_h;
	}

	void SolverVolume::computeDualLagSolution(){
		unsigned int nb_periods = this->problem->getNbPeriods();
		unsigned int nb_items = this->problem->getNbItems();

		double norme_h = 0;
		double norme_y = 0;

		for(unsigned int t=0; t<nb_periods; t++){
			norme_h += pow( abs(1-this->current_h->getSum(t)),2);
			norme_y += pow( abs(1-this->current_y->getSum(t)),2);
		}

		double coeff= (this->UB - this->current_LB) / (sqrt(norme_h)*sqrt(norme_y));

		this->pi.clear();
		for(unsigned int t=0; t<nb_periods; t++){
			this->pi.push_back( this->pi_hat[t] + std::max(0.0,THETA*coeff*(1-this->current_y->getSum(t))));
		}
		this->easy_problem->updatePi(this->pi);
	}

	void SolverVolume::computeOracle(){
		unsigned int nb_periods = this->problem->getNbPeriods();
		unsigned int nb_items = this->problem->getNbItems();

		//Step 2, Avec le programme dynamique, on calcule g
		double result = this->easy_problem->solve();
		this->current_g->update(this->easy_problem->getBestSolution());

		//On en déduit h
		matrix new_h;
		for(unsigned int i=0; i < nb_items; i++){
			std::vector<double> partial_h;
			for(unsigned int t=0; t < nb_periods; t++){
				partial_h.push_back((this->current_g->getSolution(t,i)>0));
			}
			new_h.push_back(partial_h);
		}
		this->current_h->updateSolution(new_h,result);

		//On calcul la LB
		double sum_pi = 0;
		for(unsigned int p=0; p<this->pi.size(); p++){
			sum_pi+= this->pi[p];
		}
		this->current_LB = result + sum_pi;
	}

	void SolverVolume::computePrimalSolution(){
		//Step 6 Volume, Compute a primal solution — x
		unsigned int nb_periods = this->problem->getNbPeriods();
		unsigned int nb_items = this->problem->getNbItems();

		matrix new_x;
		matrix new_y;
		double new_value = 0;

		for(unsigned int i = 0; i < nb_items; i++){
			std::vector<double> partial_x;
			std::vector<double> partial_y;
			for(unsigned int t=0; t < nb_periods; t++){
				double prod = ALPHA*this->current_x->getSolution(t,i) + (1-ALPHA)*this->current_g->getSolution(t,i);
				double setup = ALPHA*this->current_y->getSolution(t,i) + (1-ALPHA)*this->current_h->getSolution(t,i);
				new_value += prod*this->problem->getPeriodData(t,i,data::LSPeriod::PRODUCTION_COST) + setup*this->problem->getPeriodData(t,i,data::LSPeriod::SETUP_COST);
				partial_x.push_back(prod);
				partial_y.push_back(setup);
			}
			new_x.push_back(partial_x);
			new_y.push_back(partial_y);
		}
		this->current_x->updateSolution(new_x,new_value);
		this->current_y->updateSolution(new_y,new_value);
	}


	double SolverVolume::solveProblem(){
		//TODO
	}


}