#include "Solver.h"

namespace solver{
	Solver::Solver(){

	}

	Solver::~Solver(){

	}

	double Solver::solveVerbose(){
		std::cout << "Start solving problem... " << std::endl;
		auto start = std::chrono::steady_clock::now();
		double value = this->solveProblem();
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> diff = end - start;

		std::cout << "Duration " << diff.count() << " ms." << std::endl;
		std::cout << this->toString() << std::endl;

		return value;
	}

	double Solver::solve(){
		return this->solveProblem();
	}
}