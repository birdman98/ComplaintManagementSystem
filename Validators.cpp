#include "Validators.h"

#include <regex>

bool ComplaintTitle::validate(const std::string &toCheck) {
	
	std::regex pattern(".+");

	return std::regex_match(toCheck, pattern);
}

bool ComplaintedItem::validate(const std::string &toCheck) {
	
	std::regex pattern("(\\w| )+");

	return std::regex_match(toCheck, pattern);
}

bool IDData::validate(const std::string &toCheck) { 

	std::regex pattern("(([A-Z][a-z]+)| )+");

	return std::regex_match(toCheck, pattern);

}

bool Adress::validate(const std::string &toCheck) { 

	std::regex pattern("[A-Z][a-z]+ [0-9]*[A-Za-z]*/*[0-9]* *[0-9]{2}-[0-9]{3} [A-Z][a-z]+");

	return  std::regex_match(toCheck, pattern);
}

bool PhoneNumber::validate(const std::string &toCheck) {

	std::regex pattern("[1-9][0-9]{8}");

	return  std::regex_match(toCheck, pattern);
}

bool Pesel::validate(const std::string &toCheck) {
	
	std::regex pattern("[0-9]{11}");

	return std::regex_match(toCheck, pattern);
}