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

std::istream& operator>>(std::istream &input, Employee &toFill) {

	input.clear();
	input.sync();

	std::cout << "\nPodaj swoje dane jako osoby obslugujacej reklamacje: \n\n";

	std::cout << "Imie: ";
	std::getline(input, toFill.name);

	std::cout << "Nazwisko: ";
	std::getline(input, toFill.surname);

	std::cout << "Pesel: "; //jeszcze ID
	//input >> toFill.pesel;
	std::getline(input, toFill.pesel);


	return input;
}

std::ostream& operator<<(std::ostream &output, const Employee &toPrint) { //RODO, wiec wyswietlanie tylko po ID + pesel?

	std::cout << "\nDane osoby obslugujacej reklamacje: \n\n";

	std::cout << "Imie: ";
	output << toPrint.name;

	std::cout << "\nNazwisko: ";
	output << toPrint.surname;

	std::cout << "\nPesel: "; //jeszcze ID
    output << toPrint.pesel;


	return output;
}
