#include "SolverVolume.h"

namespace solver {

	SolverVolume::SolverVolume(problem::SingleItemLotSizing* problem){

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

			//Production pour la période t
			std::vector<double> prod_period(nb_items,0); 
			x.push_back(prod_period);
			y.push_back(prod_period);
			h.push_back(prod_period);

			//Définir demande
			for (unsigned int i = 0; i < nb_items; ++i){
				sum_demand[i] += this->problem->getPeriodData(t,i,data::LSPeriod::DEMAND);
			}
		}

		//création solution 0
		double value = 0;
		for(unsigned int i=0; i<nb_items; i++){
			value += sum_demand[i] * this->problem->getPeriodData(i,i,data::LSPeriod::PRODUCTION_COST);
			x[i][i] = sum_demand[i];
			y[i][i] = 1;
			h[i][i] = 1;
		}

		this->UB = value;
		this->current_x = new problem::Solution(x,value);
		this->current_y = new problem::Solution(y,value);
		this->current_h = new problem::Solution(h,value);

		//this->current_LB = 
	}

	SolverVolume::~SolverVolume(){
		for( auto b : this->bundle){
			delete b;
		}
	}

	void SolverVolume::computeDualLagSolution(){
		unsigned int nb_periods = this->problem->getNbPeriods();
		unsigned int nb_items = this->problem->getNbItems();

		double theta = 1.5;
		double norme_h = 0;
		double norme_y = 0;

		for(unsigned int t=0; t<nb_periods; t++){
			norme_h += pow( abs(1-this->current_h->getSum(t)),2);
			norme_y += pow( abs(1-this->current_y->getSum(t)),2);
		}

		double coeff= (this->UB - this->current_LB) / (sqrt(norme_h)*sqrt(norme_y));

		this->pi.clear();
		for(unsigned int t=0; t<nb_periods; t++){
			this->pi.push_back( this->pi_hat[t] + std::max(0.0,theta*coeff*(1-this->current_y->getSum(t))));
		}
	}

	void SolverVolume::computeOracle(){
		//sTEP 2 De l'algo
	}

	void SolverVolume::computePrimalSolution(){
		//Step 6 Volume, Compute a primal solution — x 
	}


	double SolverVolume::solveProblem(){

	}


}