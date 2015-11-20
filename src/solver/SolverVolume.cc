#include "SolverVolume.h"

namespace solver {

	SolverVolume::SolverVolume(problem::SingleItemLotSizing* problem){
		unsigned int nb_periods = this->problem->getNbPeriods();
		unsigned int nb_items = this->problem->getNbItems();
		std::vector<float> sum_demand;

		this->LB = std::numeric_limits<float>::min();
		this->UB = std::numeric_limits<float>::max();

		for(unsigned int i=0; i<nb_items; i++){
			sum_demand.push_back(0);
		}

		for(unsigned int t=0; t<nb_periods; t++){
			this->pi.push_back(0);
			this->pi_hat.push_back(0);

			//Production pour la période t
			std::vector<float> prod_period(nb_items,0); 
			this->current_x.push_back(prod_period);
			this->current_y.push_back(prod_period);

			for (int i = 0; i < nb_items; ++i){
				sum_demand[i] += this->problem->getPeriodData(t,i,data::LSPeriod::DEMAND);
			}
		}

		for(unsigned int i=0; i<nb_items; i++){
			this->current_x[i][i] = sum_demand[i];
			this->current_y[i][i] = 1;
		}
	}

	void SolverVolume::computeDualLagSolution(){
		//Step 1 de l'algo
	}

	void SolverVolume::computeOracle(){
		//sTEP 2 De l'algo
	}

	void SolverVolume::checkLagOptimalitySolution(){
		//Step 3 de l'algo
	}

	void SolverVolume::checkIncumbentDual(){
		//Step 4 Meilleure valeur du dual
	}

	void SolverVolume::checkDualOptimalityCondition(){
		//Step 5
	}

	void SolverVolume::computePrimalSolution(){
		//Step 6 Volume, Compute a primal solution — x 
	}

	void SolverVolume::updateIncPrimalSolution(){

	}

	void 

	float SolverVolume::solveProblem(){

	}


}