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
		virtual double solveProblem() = 0;

	public:
		Solver();
		virtual ~Solver();
		virtual double getValue() const = 0;
		virtual std::string toString() const = 0;
		double solveVerbose();
		double solve();
	};
}
#endif