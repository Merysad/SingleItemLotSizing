#ifndef _BASICLSGENERATOR_H_
#define _BASICLSGENERATOR_H_

/// \file BasicKNPGenerator.h
/// \brief Génération d'une instance de problème de Single Item Lot Sizing
/// \author Guillaume Marques <guillaume.marques33@gmail.com>
/// 
/// On considère les demandes (d_i) différentes pour chaque période et chaque item i
/// On considère les coûts de lancement (f_i) fixes pour chaque période mais différents pour chaque item i
/// On considère les coûts de production (p_i) fixes pour chaque période mais différents pour chaque item i
///
/// Le fichier en sortie est au format (pour DELIMITER=';') :
/// Période 1;d_1;f_1;p_1;d_2;f_2;p_2 ... ;

#include "Generator.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cassert>

namespace fileIO{
	class BasicLSGenerator : public Generator{
	private :
		unsigned int nb_periods;
		unsigned int nb_items;
		std::vector<int> setup_costs;
		std::vector<int> production_costs;

		static const int MAX_PRODUCTION_COST;
		static const int MAX_SETUP_COST;
		static const int MAX_DEMAND;
		static const int MAX_NB_PERIODS;
		static const int MIN_NB_ITEMS;
		static const int MAX_NB_ITEMS;
		static const char DELIMITER;

		/// \brief Initialisation du générateur
		void init();
		/// \brief Calcule une demande aléatoire
		int randomDemand() const;

		int getProductionCost(unsigned int item_id) const;
		int getSetupCost(unsigned int item_id) const;

	public:
		BasicLSGenerator(std::string filename);
		BasicLSGenerator(std::string filename, int nb_periods, int nb_items);

		/// \brief Génération et écriture des données dans un fichier (surcharge classe mère)
		void generate();
	};
}
#endif