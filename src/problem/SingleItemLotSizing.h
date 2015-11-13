#ifndef _SINGLEITEMLOTSIZING_H_
#define _SINGLEITEMLOTSIZING_H_


/// \file SingleItemLotSizing
/// \brief Instance d'un problème de SINGLE ITEM LOT SIZING
/// \author Guillaume Marques <guillaume.marques33@gmail.com>

#include "../fileIO/Parser.h"
#include "../data/LSPeriod.h"


namespace problem {
	class SingleItemLotSizing {
	private:
		std::vector< data::LSPeriod* > periods;
		virtual void initData(fileIO::Parser& parser, char delimiter);

	public:
		SingleItemLotSizing(std::string filename, char delimiter);
		virtual ~SingleItemLotSizing();
		int getPeriodData(unsigned int p, unsigned int item, unsigned int information) const;
		unsigned int getNbPeriods() const;
		virtual std::string toString() const;
	};
}
#endif