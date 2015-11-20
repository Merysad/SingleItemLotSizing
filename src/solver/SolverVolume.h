#ifndef _SOLVERVOLUME_
#define _SOLVERVOLUME_

#include <limits>
#include "Solver.h"
#include "../data/LSPeriod.h"
#include "../problem/SingleItemLotSizing.h"

namespace solver {
	class SolverVolume : public Solver {
	private:
		problem::SingleItemLotSizing* problem;

		std::vector<float> pi_hat;
		std::vector<float> pi;
		std::vector<float> z;
		std::vector< std::vector<float> > current_x;
		std::vector< std::vector<float> > current_y;
		float LB;
		float UB;

		void computeOracle(); //Calcul de z
		float solveProblem(); //Algo pour résoudre
	public:
		SolverVolume(problem::SingleItemLotSizing* problem);
		virtual ~SolverVolume();

		float getValue();
		std::string toString();
	};
}
#endif