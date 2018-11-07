#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <iostream>

class Customer {

	std::string name;
	std::string surname;
	std::string adress;
	std::string phoneNumber;
	std::string pesel;
	std::string customersID; //protected?

public:
	
	Customer();
	Customer(const std::string &name_, const std::string &surname_);

	void setName(const std::string &name);
	void setSurname(const std::string &surname);

	std::string getName() const;
	std::string getSurname() const;

	friend std::istream& operator>>(std::istream &input, Customer &toFill);
	friend std::ostream& operator<<(std::ostream &output, const Customer &toPrint);

};

