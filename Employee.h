#pragma once

#include <string>
class Employee {

	std::string name;
	std::string surname;
	std::string employeesID; //protected?

public:

	Employee();
	Employee(const std::string &name_, const std::string &surname_);

	void setName(const std::string &name);
	void setSurname(const std::string &surname);

	std::string getName() const;
	std::string getSurname() const;

};

