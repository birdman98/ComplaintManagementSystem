#include "stdafx.h"

#include "filesSupport.h"

#include <fstream>
#include <iostream>
#include <string>


filesSupport::filesSupport(const std::string& inFileName, const std::string& outFileName) :
    inFileName(inFileName),
    outFileName(outFileName) {
}

bool filesSupport::saveToFile() const {
	
	std::ofstream outFile;
	
	outFile.open(this->outFileName, std::ofstream::out);

	if(outFile.fail()) {

		std::cerr << "Blad podczas zapisu do pliku: " << strerror(errno);
	}
	

	return true;
	
}

bool filesSupport::readFromFile() const {
	
	std::ifstream inFile;

	inFile.open(this->inFileName, std::ofstream::in);

	if (inFile.fail()) {

		std::cerr << "Blad podczas otwierania pliku: " << strerror(errno);
	}


	return true;
}
