#include "Generator.h"

namespace fileIO{
	Generator::Generator(){}

	Generator::Generator(std::string filename){
		this->ostream.open(filename.c_str(), std::ios::out);
		if(!this->ostream.is_open()){
			std::cerr << "File cannot be opened" << std::endl;
		}
	}

	void Generator::writeLine(std::vector<int>& data, char delimiter){
		std::stringstream line;
		for(int &d : data){
			line << d << delimiter;
		}
		ostream << line.str() << std::endl;
		data.clear();
	}

	Generator::~Generator(){
		if(this->ostream.is_open()){
			this->ostream.close();
		}
	}
}