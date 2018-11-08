#include "stdafx.h"
#include "Complaint.h"

#include <chrono>
#include <iostream>
#include <ctime>

Complaint::Complaint() : 
	
	complaintTitle(""), //czy tu nie powinienem inicjalizowaæ danymi reklamacji, podanymi przez employee?
    complaintedItem(""), 
	customersData(), 
	employeesData(), 
	dateOfComplaint(""), 
	status(""),
	next(nullptr),
	prev(nullptr) {
}

Complaint::Complaint(const Complaint &complaint) :

	complaintTitle(complaint.complaintTitle),
	complaintedItem(complaint.complaintedItem),
	customersData(complaint.customersData),
	employeesData(complaint.employeesData),
	dateOfComplaint(complaint.dateOfComplaint),
	status(complaint.status),
	next(nullptr),
	prev(nullptr) {
}

void Complaint::setComplaintTitle(const std::string &complaintTitle) {

	this->complaintTitle = complaintTitle;
}

void Complaint::setComplaintedItem(const std::string &complaintedItem) {

	this->complaintedItem = complaintedItem;
}

void Complaint::setDateOfComplaint() { //https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
	
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string currentDateAndTime(30, '\0');

	std::strftime(&currentDateAndTime[0], currentDateAndTime.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now)); //poprawic, zeby nie rzucalo bledu

	//std::strftime(&currentDateAndTime[0], currentDateAndTime.size(), "%Y-%m-%d %H:%M:%S", std::localtime_s(&currentDateAndTime, &now));

	this->dateOfComplaint = currentDateAndTime;
}

void Complaint::setStatus(const int &statusChoice) {

	switch(statusChoice) { //pomyœleæ tu o enumach
		
	case 1: {
		this->status = accepted;
		break;
	}
	case 2: {
		
		this->status = processing;
		break;
	}
	case 3: {
		
		this->status = consideredPositive;
		break;
	}
	case 4: {

		this->status = consideredNegative;
		break;
	}
	case 5: {
		
		this->status = rejected;
		break;
	}
	}

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

int Complaint::getDuration() const {

	//return this->duration; Zaimplementowaæ ró¿nice czasu miêdzy current time a tym zapisanym w polu date

	return NULL;
}

std::string Complaint::getStatus() const {

	return this->status;
}

Complaint* Complaint::getNext() const {

	if (this == nullptr) {

		return /*this*/ nullptr;
	}
	return this->next;
}

Complaint* Complaint::getPrev() const {

	if (this == nullptr) {

		return /*this*/ nullptr;
	}

	return this->prev;
}

void Complaint::setNext(Complaint* nextToSet) {

	this->next = nextToSet;
}

void Complaint::setPrev(Complaint* prevToSet) {

	this->prev = prevToSet;
}

Complaint::~Complaint() { 
}

std::istream & operator>>(std::istream &input, Complaint &toFill) { //trzeba na getlineach

	input.clear();
	input.sync();

	std::cout << "Podaj tytul reklamacji: ";
	std::getline(input, toFill.complaintTitle);

	std::cout << "Podaj nazwe reklamowanego towaru: ";
	std::getline(input, toFill.complaintedItem);

	input >> toFill.customersData;
	input >> toFill.employeesData;
	//jeszcze status - to z jakims menu i data reklamacji - to z mojej metody

	return input;
	
}

std::ostream & operator<<(std::ostream & output, const Complaint & toPrint) {


	std::cout << "Tytul reklamacji: " << toPrint.complaintTitle << "\n";
	std::cout << "Reklamowany towar: " << toPrint.complaintedItem << "\n";
	std::cout << toPrint.customersData << "\n";
	std::cout << toPrint.employeesData << "\n";

	return output;	
}
