#include "stdafx.h"
#include "Customer.h"
#include "Validators.h"

#include <iostream>

void Customer::setName(const std::string &name) {

	this->name = name;
}

void Customer::setSurname(const std::string &surname) {

	this->surname = surname;
}

void Customer::setAdress(const std::string &adress) {
	
	this->adress = adress;
}

void Customer::setPhoneNumber(const std::string &phoneNumber) {

	this->phoneNumber = phoneNumber;
}

void Customer::setPesel(const std::string &pesel) {

	this->pesel = pesel;
}

std::string Customer::getName() const {

	return this->name;
}

std::string Customer::getSurname() const {

	return this->surname;
}

std::string Customer::getAdress() const {
	
	return this->adress;
}

std::string Customer::getPhoneNumber() const {
	
	return this->phoneNumber;
}

std::string Customer::getPesel() const {
	
	return this->pesel;
}

std::istream& operator>>(std::istream &input, Customer &toFill) { 

	Validators* IDValidator = new IDData; 
	Validators* adressValidator = new Adress;
	Validators* phoneValidator = new PhoneNumber;
	Validators* peselValidator = new Pesel;

	bool validated = true;

	input.clear();
	input.sync();

	std::cout << "\nPodaj dane osoby skladajacej reklamacje...\n\n";

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

		std::cout << "Adres: ";
		std::getline(input, toFill.adress);

		validated = adressValidator->validate(toFill.adress);

		if (!validated) {

			std::cout << "\nNiepoprawny adres! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);

	do {

		std::cout << "Numer telefonu: ";
		std::getline(input, toFill.phoneNumber);

		validated = phoneValidator->validate(toFill.phoneNumber);

		if (!validated) {

			std::cout << "\nNiepoprawny numer telefonu! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);

	do {

		std::cout << "Pesel: ";
		std::getline(input, toFill.pesel);

		validated = peselValidator->validate(toFill.pesel);

		if (!validated) {

			std::cout << "\nNiepoprawny numer pesel! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);
	
	delete IDValidator;
	delete adressValidator;
	delete phoneValidator;
	delete peselValidator;

	return input;
}

std::ostream & operator<<(std::ostream &output, const Customer &toPrint) {
	
	output << "\nDane osoby skladajacej reklamacje: \n\n";

	output << "Imie: " << toPrint.name;

	output << "\nNazwisko: " << toPrint.surname;
	
	output << "\nAdres: " << toPrint.adress;

	output << "\nNumer telefonu: " << toPrint.phoneNumber;

	output << "\nPesel: " << toPrint.pesel;

	return output;
}
