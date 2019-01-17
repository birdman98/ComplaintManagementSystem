#pragma once

#include <string>
#include <istream>
#include <ostream>

class Employee {

	std::string name;
	std::string surname;
	std::string pesel;

public:

	Employee() = default;

	void setName(const std::string &name);
	void setSurname(const std::string &surname);
	void setPesel(const std::string &pesel);
	
	std::string getName() const;
	std::string getSurname() const;
	std::string getPesel() const;

	friend std::istream& operator>>(std::istream &input, Employee &toFill);
	friend std::ostream& operator<<(std::ostream &output, const Employee &toPrint);

};

