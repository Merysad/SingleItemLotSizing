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

	double DynamicSolver::solveForItem(unsigned int i, std::vector<double>& partial_solution){
		partial_solution.clear(); //On vide partial_solution, il faudra le remplir avec la production de chaque période
		double value = 0;

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