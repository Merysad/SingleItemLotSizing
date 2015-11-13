#ifndef _PROBLEM_H_
#define _PROBLEM_H_

/// \file Solver
/// \brief Permet la resolution d'un problème
/// \author Guillaume Marques <guillaume.marques33@gmail.com>

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

namespace solver {
	class Solver{
	protected:
		virtual float solveProblem() = 0;

	public:
		Solver();
		virtual ~Solver();
		virtual float getValue() const = 0;
		virtual std::string toString() const = 0;
		float solveVerbose();
		float solve();
	};
}
#endif