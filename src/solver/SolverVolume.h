#ifndef _SOLVERVOLUME_
#define _SOLVERVOLUME_

#include <limits>
#include <cmath>
#include "Solver.h"
#include "../data/LSPeriod.h"
#include "../problem/SingleItemLotSizing.h"
#include "../problem/Solution.h"

namespace solver {
	typedef std::vector< std::vector<double> > matrix;
	class SolverVolume : public Solver {
	private:
		problem::SingleItemLotSizing* problem;

		std::vector<double> pi_hat;
		std::vector<double> pi;

		problem::Solution* current_h;
		problem::Solution* current_x;
		problem::Solution* current_y;
		std::vector< problem::Solution* > bundle;
		double current_LB;
		double best_LB;
		double UB;

		double solveProblem(); //Algo pour résoudre
		
		void computeDualLagSolution(); //step 1 (solution duale)
		void computeOracle(); //step 2 (oracle)
		void computePrimalSolution(); //step 6 (solution primale)

	public:
		SolverVolume(problem::SingleItemLotSizing* problem);
		virtual ~SolverVolume();

		double getValue();
		std::string toString();
	};
}
#endif