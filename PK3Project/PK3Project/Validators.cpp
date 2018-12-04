#include "Validators.h"

#include <regex>


bool IDData::validate(const std::string &toCheck) {

	std::regex pattern("([A-Z][a-z]+ ){2}");

	return std::regex_match(toCheck, pattern);

}
	 

bool Pesel::validate(const std::string &toCheck) {
	
	std::regex pattern("([0-9]{11}");

	return std::regex_match(toCheck, pattern);
}

bool Adress::validate(const std::string &toCheck) {
	
	std::regex pattern("[A-Z][a-z]+ [0-9]+[A-Za-z]+///[0-9]+ [0-9]{2}-[0-9]{3}"); //rozbiæ adres na kilka pól lub na oddzieln¹ klasê i porobiæ walidatory do pojedynczych pól

	return  std::regex_match(toCheck, pattern);
}

bool PhoneNumber::validate(const std::string &toCheck) {
	
	std::regex pattern("[1-9][0-9]{8}");

	return  std::regex_match(toCheck, pattern);
}
