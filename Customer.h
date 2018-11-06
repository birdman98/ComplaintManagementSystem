#pragma once

#include <string>

class Customer {

	std::string name;
	std::string surname;
	std::string customersID; //protected?

public:
	
	Customer();
	Customer(const std::string &name_, const std::string &surname_);

	void setName(const std::string &name);
	void setSurname(const std::string &surname);

	std::string getName() const;
	std::string getSurname() const;

};

