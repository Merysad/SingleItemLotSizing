#include "LSPeriod.h"

namespace data {
	const unsigned int LSPeriod::ID_PERIOD = 0;
	const unsigned int LSPeriod::PRODUCTION_COST = 3;
	const unsigned int LSPeriod::SETUP_COST = 2;
	const unsigned int LSPeriod::DATA_SIZE = 3;
	const unsigned int LSPeriod::DEMAND = 1;

	LSPeriod::LSPeriod(std::vector<int>& data)
	:Period(data) {
		this->nb_items = round((this->getSize()-1)/DATA_SIZE);
	}

	LSPeriod::~LSPeriod(){}

	int LSPeriod::getIdPeriod() const {
		return this->getPeriodData(0);
	}

	int LSPeriod::getProductionCost(unsigned int item_id) const{
		return this->getPeriodData(item_id*DATA_SIZE + PRODUCTION_COST);
	}

	int LSPeriod::getSetupCost(unsigned int item_id) const {
		return this->getPeriodData(item_id*DATA_SIZE + SETUP_COST);
	}

	int LSPeriod::getDemand(unsigned int item_id) const {
		return this->getPeriodData(item_id*DATA_SIZE + DEMAND);
	}

	unsigned int LSPeriod::getNbItems() const{
		return this->nb_items;
	}

	std::string LSPeriod::toString() const {
		std::stringstream description;

		description << "+" << std::setfill('-') << std::setw(15) << "+";

		for(unsigned int i=0; i<this->nb_items; i++){
			description << std::setw(28) << "+";
		}
		description << std::endl;

		description << std::setfill(' ');
		description << "|" << "Periode" << std::setw(3) << getIdPeriod() << std::setw(5) << "|";

		for(unsigned int i=0; i<this->nb_items; i++){
			description << "Item" << std::setw(3) << i << std::setw(21) << "|";
		}
		description << std::endl << "|" << std::setw(15) << "|";
		for(unsigned int i=0; i<this->nb_items; i++){
			description << "demande=" << std::setw(3) << getDemand(i) << std::setw(17) << "|";
		}
		description << std::endl << "|" << std::setw(15) << "|";
		for(unsigned int i=0; i<this->nb_items; i++){
			description << "p=" << std::setw(3) << getProductionCost(i)
						<< " f=" << std::setw(3) << getSetupCost(i) << std::setw(17) << "|";
		}
		return description.str();
	}
}