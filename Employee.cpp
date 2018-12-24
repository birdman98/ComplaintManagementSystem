#include "stdafx.h"
#include "Employee.h"
#include "Validators.h"


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

void Employee::setPesel(const std::string &pesel) {
	
	this->pesel = pesel;
}

void Employee::setID(const std::string &id) {

	this->employeesID = id;
}

std::string Employee::getName() const {

	return this->name;
}

std::string Employee::getSurname() const {

	return this->surname;
}

std::istream& operator>>(std::istream &input, Employee &toFill) {

	Validators* IDValidator = new IDData;
	Validators* peselValidator = new Pesel;

	bool validated = true;

	input.clear();
	input.sync();

	std::cout << "\nPodaj swoje dane jako osoby obslugujacej reklamacje: \n\n";

	do {

		std::cout << "Imie: ";
		std::getline(input, toFill.name);

		validated = IDValidator->validate(toFill.name);

		if (!validated) {

			std::cout << "\nNiepoprawne imie! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);

	do {

		std::cout << "Nazwisko: ";
		std::getline(input, toFill.surname);

		validated = IDValidator->validate(toFill.surname);

		if (!validated) {

			std::cout << "\nNiepoprawne nazwisko! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);

	do {

		std::cout << "Pesel: "; 
		std::getline(input, toFill.pesel);

		validated = peselValidator->validate(toFill.pesel);

		if (!validated) {

			std::cout << "\nNiepoprawny pesel! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);
	

	delete IDValidator;
	delete peselValidator;

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
