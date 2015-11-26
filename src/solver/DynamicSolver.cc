#include "DynamicSolver.h"

namespace solver {
	DynamicSolver::DynamicSolver(problem::SingleItemLotSizing* p){
		this->problem = p;
		this->best_solution = new problem::Solution();
	}

	DynamicSolver::~DynamicSolver(){}

	void DynamicSolver::updatePi(std::vector<double> pi){
		this->current_pi = pi;
	}

	double DynamicSolver::getValue() const {
		return this->best_solution->getValue();
	}

	std::string DynamicSolver::toString() const {
		return "..."; //On verra plus tard
	}

	double DynamicSolver::g(unsigned int i, unsigned int k, unsigned int t, double best, int& demand){
		double prod = this->problem->getPeriodData(k,i,data::LSPeriod::PRODUCTION_COST);
		double setup = this->problem->getPeriodData(k,i,data::LSPeriod::SETUP_COST);
		demand = 0;
		for(unsigned int f=k; f<t; f++){
			demand += this->problem->getPeriodData(f,i, data::LSPeriod::DEMAND);
		}
		return best + demand*prod + setup;
	}

	double DynamicSolver::solveForItem(unsigned int i, std::vector<double>& partial_solution){
		std::vector<dyn_solution> best_g;
		partial_solution.clear(); //On vide partial_solution, il faudra le remplir avec la production de chaque période
		int demand;
		dyn_solution init = {nullptr, 0, -1, 0};
		best_g.push_back(init);

		for(unsigned int t=0; t<this->problem->getNbPeriods(); t++){
			partial_solution.push_back(0);
			dyn_solution best_for_t = { &best_g[t], 0, 0, 0 };
			for(unsigned int k=0; k<=t; k++){
				double new_value = g(i,k,t, best_g[k].value, demand);
				if(best_for_t.value < new_value){
					best_for_t.precedent = &best_g[k];
					best_for_t.value = new_value;
					best_for_t.period = k;
					best_for_t.prod = demand;
				}
			}
			best_g.push_back(best_for_t);
		}

		dyn_solution p = best_g[this->problem->getNbPeriods()];
		double value = best_g[this->problem->getNbPeriods()].value;
		while(p.precedent != nullptr){
			partial_solution[p.period] = p.prod;
		}

		//TODO Implémenter le programme dynamique M(i,1,T+1) du rapport
		//Remplir le vecteur partial_solution avec la solution partielle (c'est à dire la production d'item i pour chaque période, on déduira y)
		//Renvoyer le vecteur value avec la valeur de la solution partielle

		return value;
	}

	double DynamicSolver::solveProblem(){
		double value = 0;
		std::vector< std::vector<double> > solution;
		std::vector<double> partial_solution;

		for(unsigned int i=0; i<this->problem->getNbItems(); i++){
			value += solveForItem(i,partial_solution);
			solution.push_back(partial_solution);
		}

		
		this->best_solution->updateSolution(solution,value);
		return value;
	}

	problem::Solution DynamicSolver::getBestSolution() const{
		return *this->best_solution;
	}
}