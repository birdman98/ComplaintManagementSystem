#include "stdafx.h"
#include "Complaint.h"
#include "Validators.h"

#include <chrono>
#include <iostream>
#include <ctime>

Complaint::Complaint() : 
	
	complaintTitle(""), 
    complaintedItem(""),  
	dateOfComplaint(""), 
	status(""),
	customersData(),
	employeesData(),
	next(nullptr),
	prev(nullptr) {
}

Complaint::Complaint(const Complaint &complaint) :

	complaintTitle(complaint.complaintTitle),
	complaintedItem(complaint.complaintedItem),
	dateOfComplaint(complaint.dateOfComplaint),
	status(complaint.status),
	customersData(complaint.customersData),
	employeesData(complaint.employeesData),
	next(nullptr),
	prev(nullptr) {
}

void Complaint::setComplaintTitle(const std::string &complaintTitle) {

	this->complaintTitle = complaintTitle;
}

void Complaint::setComplaintedItem(const std::string &complaintedItem) {

	this->complaintedItem = complaintedItem;
}

void Complaint::setDateOfComplaint(const std::string &date) { //https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono

	if(date != "auto") {
		
		this->dateOfComplaint = date;

		return;
	}

	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string currentDateAndTime(30, '\0');

	std::strftime(&currentDateAndTime[0], currentDateAndTime.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now)); 

	this->dateOfComplaint = currentDateAndTime;
}

void Complaint::setStatus(const int &statusChoice) {

	switch(statusChoice) {
		
	case accepted: {

		this->status = "przyjeta";

		break;
	}
	case processing: {
		
		this->status = "w toku";

		break;
	}
	case consideredPositive: {
		
		this->status = "rozpatrzona pozytywnie";

		break;
	}
	case consideredNegative: {

		this->status = "rozpatrzona negatywnie";

		break;
	}
	case rejected: {
		
		this->status = "odrzucona";

		break;
	}
	}

}

void Complaint::setStatus(const std::string &status) {
	
	this->status = status;  
}

void Complaint::setCustomersData(const Customer &customersData) {
	
	this->customersData = customersData;
}

void Complaint::setEmployeesData(const Employee &employeesData) {
	
	this->employeesData = employeesData;
}

void Complaint::setNext(Complaint* nextToSet) {

	this->next = nextToSet;
}

void Complaint::setPrev(Complaint* prevToSet) {

	this->prev = prevToSet;
}

std::string Complaint::getComplaintTitle() const {

	return this->complaintTitle;
}

std::string Complaint::getComplaintedItem() const {

	return this->complaintedItem;
}

std::string Complaint::getDateOfComplaint() const {

	return this->dateOfComplaint;
}

std::string Complaint::getStatus() const {

	return this->status;
}

Customer Complaint::getCustomersData() const {

	return this->customersData;
}

Employee Complaint::getEmployeesData() const {
	
	return this->employeesData;
}

Complaint* Complaint::getNext() const {

	if (this == nullptr) {

		return nullptr;
	}

	return this->next;
}

Complaint* Complaint::getPrev() const {

	if (this == nullptr) {

		return nullptr;
	}

	return this->prev;
}

bool Complaint::checkIfNeedsToBeExamined(int &durationInDays) const { //je¿eli dana reklamacja w przybli¿eniu oczekuje na rozpatrzenie d³u¿ej ni¿ 14 dni to zwracane true

	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string currentDateAndTime(30, '\0');

	std::strftime(&currentDateAndTime[0], currentDateAndTime.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

	int dayNow = stoi(currentDateAndTime.substr(8, 2));
	int monthNow = stoi(currentDateAndTime.substr(5, 2));
	int yearNow = stoi(currentDateAndTime.substr(0, 4));
	
	int day = stoi(this->dateOfComplaint.substr(8, 2));
	int month = stoi(this->dateOfComplaint.substr(5, 2));
	int year = stoi(this->dateOfComplaint.substr(0, 4));

	if(yearNow == year) {

		durationInDays = dayNow - day + (monthNow - month) * 30;

	} else {

		durationInDays = (yearNow - year - 1) * 365 + (dayNow - day) + (monthNow - month + 12) * 30;

	}	

	if(durationInDays >= almostDeadline) {

		return true;
	}

	return false;
	
}

std::istream& operator>>(std::istream &input, Complaint &toFill) { 

	Validators* titleValidator = new ComplaintTitle; 
	Validators* itemValidator = new ComplaintedItem;

	bool validated = true;

	input.clear(); 
	input.sync();
	
	do {

		std::cout << "Podaj tytul reklamacji: ";
		std::getline(input, toFill.complaintTitle);

		validated = titleValidator->validate(toFill.complaintTitle);

		if(!validated) {
			
			std::cout << "\nNiepoprawny tytul reklamacji! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);
	
	do {

		std::cout << "Podaj nazwe reklamowanego towaru: ";
		std::getline(input, toFill.complaintedItem);

		validated = itemValidator->validate(toFill.complaintedItem);

		if (!validated) {

			std::cout << "\nNiepoprawna nazwa reklamowanego towaru! Sprobuj jeszcze raz.\n\n";
		}

	} while (validated == false);	
	
	
	delete titleValidator;
	delete itemValidator;

	input >> toFill.customersData;
	input >> toFill.employeesData;
	
	return input;
	
}

std::ostream& operator<<(std::ostream &output, const Complaint &toPrint) {


	output << "Tytul reklamacji: " << toPrint.complaintTitle << "\n";
	output << "Reklamowany towar: " << toPrint.complaintedItem << "\n";
	output << "Data przyjecia reklamacji: " << toPrint.dateOfComplaint << "\n";
	output << "Status reklamacji: " << toPrint.status << "\n";
	output << toPrint.customersData << "\n";
	output << toPrint.employeesData << "\n";
	

	return output;	
}