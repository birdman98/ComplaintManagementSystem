#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <iostream>

class Employee {

	std::string name;
	std::string surname;
	std::string pesel;
	std::string employeesID; //protected?

public:

	Employee();
	Employee(const std::string &name_, const std::string &surname_);

	void setName(const std::string &name);
	void setSurname(const std::string &surname);
	void setPesel(const std::string &pesel);
	void setID(const std::string &id);

	std::string getName() const;
	std::string getSurname() const;
	std::string getPesel() const;
    std::string getID() const;

	friend std::istream& operator>>(std::istream &input, Employee &toFill);
	friend std::ostream& operator<<(std::ostream &output, const Employee &toPrint);

};

