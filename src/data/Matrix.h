#ifndef _MATRIX_
#define _MATRIX_

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace data {
	template<class T>
	class Matrix {

	private:
		std::vector<T> data;
		unsigned int n;
		unsigned int m;

	public:
		Matrix(const Matrix<T>& m);
		Matrix(unsigned int n, unsigned int m, const T& value);
		~Matrix();

		void reset(const T& value);
		T get(unsigned int i, unsigned int j) const;
		void set(unsigned int, unsigned int j, const T& value);
		void setLine(unsigned int l, const T& value);
		void setColumn(unsigned int c, const T& value);
		T getMaximumValue(unsigned int& i, unsigned int& j) const;
		T getMaximumValueOnLine(unsigned int l, unsigned int& pos) const;
		std::string toString() const;
	};
}
#include "Matrix.tpp"
#endif