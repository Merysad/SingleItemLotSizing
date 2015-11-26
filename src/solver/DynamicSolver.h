#ifndef _DYNAMICSOLVER_H_
#define _DYNAMICSOLVER_H_

#include "Solver.h"
#include "../problem/SingleItemLotSizing.h"
#include "../problem/Solution.h"
#include <vector>

namespace solver{

	struct dyn_solution {
		dyn_solution* precedent;
		double value;
		int prod;
		unsigned int period;
	};

	class DynamicSolver : public Solver {
	private:
		problem::SingleItemLotSizing* problem;

		std::vector<double> current_pi;
		problem::Solution* best_solution;

		double g(unsigned int i, unsigned int k, unsigned int t, double best, int& demand);
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