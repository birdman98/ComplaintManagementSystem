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

	std::strftime(&currentDateAndTime[0], currentDateAndTime.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

	this->dateOfComplaint = currentDateAndTime;
}

void Complaint::setStatus(const std::string &status) {

	this->status = status;

}

std::string Complaint::getComplaintName() const {

	return this->complaintTitle;
}

std::string Complaint::getComplaintedItem() const {

	return this->complaintedItem;
}

std::string Complaint::getDateOfComplaint() const {

	return this->dateOfComplaint;
}

int Complaint::getDuration() const {

	return this->duration;
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

std::istream & operator>>(std::istream & input, Complaint & toFill)
{
	// TODO: tu wstawiæ instrukcjê return
}

std::ostream & operator<<(std::ostream & output, Complaint & toPrint)
{
	// TODO: tu wstawiæ instrukcjê return
}
