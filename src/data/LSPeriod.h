#ifndef _LSPERIOD_H_
#define _LSPERIOD_H_

/// \file LSPeriod
/// \brief Enregistre les données d'une période
/// \author Guillaume Marques <guillaume.marques33@gmail.com>
/// Une période correspond à une demande, un cout de production, un cout de lancement

#include <iomanip>
#include <vector>
#include <cmath>
#include "Period.h"

namespace data {
	class LSPeriod : public Period {
	private:
		unsigned int nb_items;

	public:
		static const unsigned int ID_PERIOD;
		static const unsigned int PRODUCTION_COST;
		static const unsigned int SETUP_COST;
		static const unsigned int DATA_SIZE;
		static const unsigned int DEMAND;

		LSPeriod(std::vector<int>& data);
		~LSPeriod();
		int getIdPeriod() const;
		int getProductionCost(unsigned int item_id) const;
		int getSetupCost(unsigned int item_id) const;
		int getDemand(unsigned int item_id) const;
		std::string toString() const;
	};
}
#endif