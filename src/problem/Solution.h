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
		Solution();
		Solution(std::vector< std::vector<double> >& s, double v);
		~Solution();
		void updateSolution(std::vector< std::vector<double> >& s, double v);
		void update(Solution s);
		double getValue() const;
		double getSolution(unsigned int t, unsigned int i) const;
		double getSum(unsigned int t) const;
	};
}
#endif