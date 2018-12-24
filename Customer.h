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
	void setAdress(const std::string &adress);
	void setPhoneNumber(const std::string &phoneNumber);
	void setPesel(const std::string &pesel);
	void setID(const std::string &id);

	std::string getName() const;
	std::string getSurname() const;
	std::string getAdress() const;
	std::string getPhoneNumber() const;
	std::string getPesel() const;
	std::string getID() const;

	friend std::istream& operator>>(std::istream &input, Customer &toFill);
	friend std::ostream& operator<<(std::ostream &output, const Customer &toPrint);

};

