#include "Period.h"

namespace data{
	Period::Period(std::vector<int>& data){
		this->size = data.size();
		this->data = new int[this->size];
		for(unsigned int i=0; i<this->size; i++){
			this->data[i] = data[i];
		}
		data.clear();
	}

	Period::~Period(){
		delete[] this->data;
	}

	int Period::getPeriodData(unsigned int pos) const{
		assert(pos < this->size);
		return this->data[pos];
	}

	unsigned int Period::getSize() const{
		return this->size;
	}

	std::string Period::toString() const{
		std::stringstream description;
		description << "(" << this->size << ")[";
		for(unsigned int i=0; i<this->size-1; i++){
			description << this->data[i] << ", ";
		}
		description << this->data[this->size-1] << "]";
		return description.str();
	}
}