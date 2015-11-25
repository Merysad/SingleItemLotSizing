#ifndef _DYNAMICSOLVER_H_
#define _DYNAMICSOLVER_H_

#include "Solver.h"
#include "../problem/SingleItemLotSizing.h"
#include "../problem/Solution.h"
#include <vector>

namespace solver{
	class DynamicSolver : public Solver {
	private:
		problem::SingleItemLotSizing* problem;

		std::vector<double> current_pi;
		problem::Solution* best_solution;

		double solveForItem(unsigned int i, std::vector<double>& partial_solution);
		double solveProblem();

	public:
		DynamicSolver(problem::SingleItemLotSizing* p);
		~DynamicSolver();

		void updatePi(std::vector<double> pi);
		problem::Solution getBestSolution() const;

		double getValue() const;
		std::string toString() const;
	};
}
#endif