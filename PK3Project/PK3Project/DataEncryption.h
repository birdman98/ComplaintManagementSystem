#pragma once

#include <string>

class DataEncryption { //dziedziczenie po protected z Customer i Employee?
public:
	
	static std::string makeIDForUser(std::string name, std::string surname, std::string position);

	~DataEncryption();
};

