#pragma once

#include <string>
#include "ListOfComplaints.h"


class ListOfComplaints;

class filesSupport
{

	const std::string inFileName;
	const std::string outFileName;

public:

	filesSupport(const std::string& inFileName, const std::string& outFileName);

	bool saveToFile(ListOfComplaints &list) const;
	bool readFromFile(ListOfComplaints &list) const;


};

