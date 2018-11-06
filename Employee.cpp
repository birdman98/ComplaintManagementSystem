#include "stdafx.h"
#include "Employee.h"


Employee::Employee() :

	name(""),
	surname(""),
    employeesID("") {
}

Employee::Employee(const std::string &name_, const std::string &surname_) :

	name(name_),
	surname(surname_) {

	//this->employeesID = makeIDForUser();
}

void Employee::setName(const std::string &name) {

	this->name = name;
}

void Employee::setSurname(const std::string &surname) {

	this->surname = surname;
}

std::string Employee::getName() const {

	return this->name;
}

std::string Employee::getSurname() const {

	return this->surname;
}
