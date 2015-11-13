#ifndef _PERIOD_H_
#define _PERIOD_H_

/// \file Period
/// \brief Contient les données d'une période
/// \author Guillaume Marques <guillaume.marques33@gmail.com>
/// La nature des données est détaillées dans une classe fille

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace data{
	class Period{
	private:
		int* data;
		unsigned int size;

	public:
		Period(std::vector<int>& data);
		virtual ~Period();
		int getPeriodData(unsigned int pos) const;
		unsigned int getSize() const;
		virtual std::string toString() const;
	};
}
#endif