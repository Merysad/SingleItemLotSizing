#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <cstdlib>
#include <vector>

namespace problem {
	class Solution {
	private:
		std::vector< std::vector<double> > solution;
		double value;
	public:
		Solution(std::vector< std::vector<double> >& s, double v);
		~Solution();

		double getValue() const;
		double getSolution(unsigned int t, unsigned int i) const;
		double getSum(unsigned int t) const;
	};
}
#endif