#include "Solution.h"

namespace problem{
	Solution::Solution(std::vector< std::vector<double> >& s, double v){
		this->solution = s;
		this->value = v;
	}

	Solution::~Solution(){}

	double Solution::getValue() const {
		return this->value;
	}

	double Solution::getSolution(unsigned int t, unsigned int i) const {
		return this->solution[t][i];
	}

	double Solution::getSum(unsigned int t) const{
		double sum=0;
		for(unsigned int i=0; i<this->solution[t].size(); i++){
			sum+=this->solution[t][i];
		}
		return sum;
	}
}