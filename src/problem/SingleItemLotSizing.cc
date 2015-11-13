#include "SingleItemLotSizing.h"

namespace problem{
	SingleItemLotSizing::SingleItemLotSizing(std::string filename, char delimiter){
		fileIO::Parser parser(filename);
		this->initData(parser, delimiter);
	}

	SingleItemLotSizing::~SingleItemLotSizing(){
		for(data::LSPeriod* period : this->periods){
			delete period;
		}
		this->periods.clear();
	}

	void SingleItemLotSizing::initData(fileIO::Parser& parser, char delimiter){
		std::vector<int> data_line;
		while(parser.getData(data_line,delimiter)){
			this->periods.push_back(new data::LSPeriod(data_line));
		}
	}

	unsigned int SingleItemLotSizing::getNbPeriods() const{
		return this->periods.size();
	}

	int SingleItemLotSizing::getPeriodData(unsigned int p, unsigned int item, unsigned int information) const {
		return this->periods[p]->getPeriodData(item*data::LSPeriod::DATA_SIZE + information);
	}

	std::string SingleItemLotSizing::toString() const{
		std::stringstream description;
		description << "SingleItemLotSizing PROBLEM" << std::endl
					<< "# Periods : " << this->getNbPeriods() << std::endl;
		for(data::LSPeriod* period : this->periods){
			description << period->toString() << std::endl;
		}
		return description.str();
	}
}