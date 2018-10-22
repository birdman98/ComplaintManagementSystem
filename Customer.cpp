#include "stdafx.h"
#include "Customer.h"


Customer::Customer() :

	name(""),
	surname("") {
}

Customer::Customer(const std::string &name_, const std::string &surname_) :

	name(name_),
	surname(surname_) {
}

void Customer::setName(const std::string &name) {

	this->name = name;
}

void Customer::setSurname(const std::string &surname) {

	this->surname = surname;
}

std::string Customer::getName() const {

	return this->name;
}

std::string Customer::getSurname() const {

	return this->surname;
}

