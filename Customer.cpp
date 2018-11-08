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

std::istream & operator>>(std::istream &input, Customer &toFill) { //wywo³ywaæ metodê do walidacji danych - regex, exceptions

	input.clear();
	input.sync();

	std::cout << "\nPodaj dane osoby skladajacej reklamacje...\n\n";

	std::cout << "Imie: ";
	std::getline(input, toFill.name);

	std::cout << "Nazwisko: ";
	std::getline(input, toFill.surname);

	std::cout << "Adres: ";
	std::getline(input, toFill.adress);

	std::cout << "Numer telefonu: ";
	std::getline(input, toFill.phoneNumber);

	std::cout << "Pesel: ";
	//input >> toFill.pesel; //jeszcze ID, dlaczego do employee lapie bialy znak jak tu nie ma getlinea?
	std::getline(input, toFill.pesel); 

	return input;
}

std::ostream & operator<<(std::ostream &output, const Customer &toPrint) {
	
	std::cout << "\nDane osoby skladajacej reklamacje: \n\n";

	std::cout << "Imie: ";
	output << toPrint.name;

	std::cout << "\nNazwisko: ";
	output << toPrint.surname;

	std::cout << "\nAdres: ";
	output << toPrint.adress;

	std::cout << "\nNumer telefonu: ";
	output << toPrint.phoneNumber;

	std::cout << "\nPesel: ";
	output << toPrint.pesel; //jeszcze ID

	return output;
}
