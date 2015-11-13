#ifndef _GENERATOR_H_
#define _GENERATOR_H_

/// \file Generator.h
/// \brief Ecriture dans un fichier de données
/// \author Guillaume Marques <guillaume.marques33@gmail.com>
///
/// Les données (instance de problème) doivent être générées par une classe fille
///

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

namespace fileIO{
	class Generator{
	private:
		std::ofstream ostream;

	protected:
		/// \brief écriture des données d'un vecteur dans un fichier
		/// \param data Les données à écrire.
		/// \param delimiter Le caractère qui séparera deux données dans le fichier
		/// L'écriture de ces données est suivi d'un saut à la ligne
		void writeLine(std::vector<int>& data, char delimiter);

	public:
		Generator();
		Generator(std::string filename);
		virtual ~Generator();
		/// \brief Génération et écriture des données dans un fichier
		virtual void generate() = 0;
	};
}
#endif