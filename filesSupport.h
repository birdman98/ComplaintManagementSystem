#pragma once

#include <string>
#include <iostream>


class filesSupport
{

private:
	std::string inFileName;
	std::string outFileName;

public:
	filesSupport(const std::string& inFileName, const std::string& outFileName);

	bool saveToFile(const std::string& outFileName);
	bool readFromFile(const std::string& inFileName);


};

