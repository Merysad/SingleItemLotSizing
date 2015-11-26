#ifndef _SOLVERVOLUME_
#define _SOLVERVOLUME_

#include <limits>
#include <cmath>
#include "Solver.h"
#include "DynamicSolver.h"
#include "../data/LSPeriod.h"
#include "../problem/SingleItemLotSizing.h"
#include "../problem/Solution.h"

namespace solver {
	typedef std::vector< std::vector<double> > matrix;

	class SolverVolume : public Solver {
	private:

		static constexpr double THETA = 1.5;
		static constexpr double ALPHA = 0.7;
		static constexpr double EPSILON = 2.0;

		problem::SingleItemLotSizing* problem;
		solver::DynamicSolver* easy_problem;

		std::vector<double> pi_hat;
		std::vector<double> pi;

		problem::Solution* current_g;
		problem::Solution* current_h;
		problem::Solution* current_x;
		problem::Solution* current_y;
		//std::vector< problem::Solution* > bundle;
		double current_LB;
		double best_LB;
		double UB;

		void init();

		double solveProblem(); //Algo pour résoudre
		
		void computeDualLagSolution(); //step 1 (solution duale)
		void computeOracle(); //step 2 (oracle)
		void computePrimalSolution(); //step 6 (solution primale)

	public:
		SolverVolume(problem::SingleItemLotSizing* problem);
		~SolverVolume();

		double getValue() const;
		std::string toString() const;
	};
}
#endif