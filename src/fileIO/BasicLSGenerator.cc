#include "BasicLSGenerator.h"

/// \author Guillaume Marques <guillaume.marques33@gmail.com>

namespace fileIO{
	
	const int BasicLSGenerator::MAX_PRODUCTION_COST = 40;
	const int BasicLSGenerator::MAX_SETUP_COST = 40;
	const int BasicLSGenerator::MAX_DEMAND = 150;
	const int BasicLSGenerator::MAX_NB_PERIODS = 15;
	const int BasicLSGenerator::MIN_NB_ITEMS = 2;
	const int BasicLSGenerator::MAX_NB_ITEMS = 5; // doit être inférieur à MAX_NB_PERIODS
	const char BasicLSGenerator::DELIMITER = ';';

	BasicLSGenerator::BasicLSGenerator(std::string filename)
	:Generator(filename){
		this->nb_periods = MIN_NB_ITEMS + rand()%(MAX_NB_PERIODS - MIN_NB_ITEMS);
		this->nb_items = MIN_NB_ITEMS + rand()%(MAX_NB_ITEMS - MIN_NB_ITEMS);
		init();
	}

	BasicLSGenerator::BasicLSGenerator(std::string filename, int nb_periods, int nb_items)
	:Generator(filename), nb_periods(nb_periods), nb_items(nb_items) {
		assert(this->nb_periods > this->nb_items);
		init();
	}

	void BasicLSGenerator::init(){
		srand(time(NULL));
		//Initialisation des vecteurs de coût
		for(unsigned int i=0; i<this->nb_items; i++){
			int production_cost = MAX_PRODUCTION_COST/2 + rand()%(MAX_PRODUCTION_COST/2);
			int setup_cost = MAX_SETUP_COST/2 + rand()%(MAX_SETUP_COST/2);

			this->production_costs.push_back(production_cost);
			this->setup_costs.push_back(setup_cost);
		}
	}

	int BasicLSGenerator::randomDemand() const{
		return rand()%MAX_DEMAND+1;
	}

	int BasicLSGenerator::getProductionCost(unsigned int item_id) const {
		assert(item_id >=0 && item_id < this->production_costs.size());
		return this->production_costs[item_id];
	}

	int BasicLSGenerator::getSetupCost(unsigned int item_id) const {
		assert(item_id >=0 && item_id < this->setup_costs.size());
		return this->setup_costs[item_id];
	}

	void BasicLSGenerator::generate(){
		std::vector<int> item_data; //une ligne de données

		//Creating all periods
		for(unsigned int p = 0; p < this->nb_periods; p++){
			item_data.push_back(p); // numéro de période

			for(unsigned int i=0; i < this->nb_items; i++){
				//Demande
				if( i <= p ){
					item_data.push_back(this->randomDemand());
				} else {
					item_data.push_back(0);
				}
				//Cout de lancement
				item_data.push_back(this->getSetupCost(i));
				//Cout de production
				item_data.push_back(this->getProductionCost(i));
			}
			this->writeLine(item_data,DELIMITER);
		}
	}
}