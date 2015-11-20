#include <iostream>
#include <array>
#include <cstdlib>
#include <sstream>
#include "fileIO/BasicLSGenerator.h"
#include "problem/SingleItemLotSizing.h"

int main(int argc, char** argv){

	int NB_ITEMS = 3;
	int NB_PERIODS = 12;

   
	fileIO::Generator* g = new fileIO::BasicLSGenerator("play/test", NB_PERIODS, NB_ITEMS);
	g->generate();
	delete g;

	//Création de l'instance du problème
	problem::SingleItemLotSizing* sils = new problem::SingleItemLotSizing("play/test", ';');
	std::cout << sils->toString() << std::endl;

	/*std::cout << "Exemple:" << std::endl
			  << "Cout de setup, periode 0, item 1 " << sils->getPeriodData(0,1,data::LSPeriod::SETUP_COST) << std::endl;
	*/
	delete sils;

	return EXIT_SUCCESS;
}
