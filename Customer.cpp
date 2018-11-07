#include "stdafx.h"
#include "Customer.h"


Customer::Customer() :

	name(""),
	surname(""),
    adress(""),
    phoneNumber(""),
    pesel(""),
    customersID("") {
}

Customer::Customer(const std::string &name_, const std::string &surname_) : //argumenty dla reszty pól

	name(name_),
	surname(surname_) {

	//this->customersID = makeIDForUser();
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

std::istream & operator>>(std::istream &input, Customer &toFill) {

	std::cout << "Podaj dane osoby skladajacej reklamacje...\n\n";

	std::cout << "Imie: ";
	input >> toFill.name;

	std::cout << "Nazwisko: ";
	input >> toFill.surname;

	std::cout << "Adres (oddziel ulice od kodu pocztowego ,): ";
	input >> toFill.adress;

	std::cout << "Numer telefonu: ";
	input >> toFill.phoneNumber;

	std::cout << "Pesel: ";
	input >> toFill.pesel; //jeszcze ID

	return input;
}

std::ostream & operator<<(std::ostream &output, const Customer &toPrint) {
	
	std::cout << "Dane osoby skladajacej reklamacje: \n\n";

	std::cout << "Imie: ";
	output << toPrint.name;

	std::cout << "Nazwisko: ";
	output << toPrint.surname;

	std::cout << "Adres (oddziel ulice od kodu pocztowego ,): ";
	output << toPrint.adress;

	std::cout << "Numer telefonu: ";
	output << toPrint.phoneNumber;

	std::cout << "Pesel: ";
	output << toPrint.pesel; //jeszcze ID

	return output;
}
