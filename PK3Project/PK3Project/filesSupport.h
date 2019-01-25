#pragma once

#include <string>
#include "ListOfComplaints.h"

class filesSupport {

	const std::string inFileName;
	const std::string outFileName;

public:

	filesSupport(const std::string& inFileName, const std::string& outFileName);

	bool saveToFile(ListOfComplaints &list) const;
	bool readFromFile(ListOfComplaints &list) const;

	friend std::ofstream& operator<<(std::ofstream &outFile, const Complaint* current); 
	friend std::ifstream& operator>>(std::ifstream &inFile, Complaint &complaint);

};

