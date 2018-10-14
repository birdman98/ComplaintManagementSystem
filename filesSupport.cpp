#include "stdafx.h"

#include "filesSupport.h"

#include <fstream>
#include <iostream>
#include <string>


filesSupport::filesSupport(const std::string& inFileName, const std::string& outFileName)
{

	this->inFileName = inFileName;
	this->outFileName = outFileName;
}

bool filesSupport::saveToFile(const std::string &outFileName) //biblioteka do obs³ugi b³edów plików
{
	std::ofstream outFile;
	
	outFile.open(outFileName, std::ofstream::out);

	std::cout << "Podaj prosze tekst do zapisania do pliku: \n\n";

	std::string toSave = "";
	
	std::getline(std::cin, toSave);

	outFile << toSave;

	if (outFile.good())
	{
		std::cout << "Zapis udany!\n\n";

		outFile.close();
		return true;

	}
	else {


		std::cout << "Zapis nieudany!\n\n";

		outFile.close();
		return false;

	}
	
}

bool filesSupport::readFromFile(const std::string &inFileName)
{
	//

	return false;
}
