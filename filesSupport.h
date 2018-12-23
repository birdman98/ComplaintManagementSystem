#pragma once

#include <string>
#include <iostream>


class filesSupport
{

private:
	const std::string inFileName;
	const std::string outFileName;

public:

	filesSupport(const std::string& inFileName, const std::string& outFileName);

	bool saveToFile() const;
	bool readFromFile() const;


};

