#include "Parser.h"

namespace fileIO{
	Parser::Parser(std::string filename){
		this->istream.open(filename.c_str(), std::ios::in);
		if(!this->istream.is_open()){
			std::cerr << "File cannot be opened" << std::endl;
		}
	}

	Parser::~Parser(){
		if(this->istream.is_open()){
			this->istream.close();
		}
	}

	bool Parser::getData(std::vector<int>& line, char delimiter){
		line.clear();
		std::string data;
		if(std::getline(this->istream, data)){
			std::istringstream iss(data);
			while(std::getline(iss, data, delimiter)){
				line.push_back(atoi(data.c_str()));
			}
		} else {
			return false;
		}
		return true;
	}
}