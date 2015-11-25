#include "Solution.h"

namespace problem{

	Solution::Solution(){ }

	Solution::Solution(std::vector< std::vector<double> >& s, double v){
		this->solution = s;
		this->value = v;
	}

	Solution::~Solution(){}

	double Solution::getValue() const {
		return this->value;
	}

	double Solution::getSolution(unsigned int t, unsigned int i) const {
		return this->solution[i][t];
	}

	void Solution::updateSolution(std::vector< std::vector<double> >& s, double v){
		this->solution = s;
		this->value = v;
	}

	void Solution::update(Solution s){
		this->solution = s.solution;
		this->value = s.value;
	}

	double Solution::getSum(unsigned int t) const{
		double sum=0;
		for(unsigned int i=0; i<this->solution[t].size(); i++){
			sum+=this->solution[i][t];
		}
		return sum;
	}
}