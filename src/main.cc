#include <iostream>
#include <array>
#include <cstdlib>
#include <sstream>
#include "fileIO/BasicLSGenerator.h"
#include "problem/SingleItemLotSizing.h"

int main(int argc, char** argv){

    //20 périodes et 3 items
	fileIO::Generator* g = new fileIO::BasicLSGenerator("play/test", 12, 3);
	g->generate();
	delete g;

	//Création de l'instance du problème
	problem::SingleItemLotSizing* sils = new problem::SingleItemLotSizing("play/test", ';');
	std::cout << sils->toString() << std::endl;
	delete sils;

	return EXIT_SUCCESS;
}
