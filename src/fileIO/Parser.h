#ifndef _PARSER_H_
#define _PARSER_H_

/// \file Parser
/// \brief Lecture d'un fichier contenant une instance
/// \author Guillaume Marques <guillaume.marques33@gmail.com>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace fileIO{
	class Parser{
	private:
		std::ifstream istream;

	public:
		Parser(std::string filename);
		~Parser();

		// Les données de chaque ligne sont enregistrées dans un vector
		bool getData(std::vector<int>& line, char delimiter);
	};
}
#endif