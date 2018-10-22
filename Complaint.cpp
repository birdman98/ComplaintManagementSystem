#include "stdafx.h"
#include "Complaint.h"


Complaint::Complaint() : 
	
	complaintName(""), //czy tu nie powinienem inicjalizowaæ danymi reklamacji, podanymi przez employee?
    complaintedItem(""), 
	customersData(), 
	employeesData(), 
	dateOfComplaint(""), 
	duration(NULL),
	status(""),
	next(nullptr),
	prev(nullptr) {
}

Complaint::Complaint(const Complaint &complaint) :

	complaintName(complaint.complaintName),
	complaintedItem(complaint.complaintedItem),
	customersData(complaint.customersData),
	employeesData(complaint.employeesData),
	dateOfComplaint(complaint.dateOfComplaint),
	duration(NULL), //??
	status(complaint.status),
	next(nullptr),
	prev(nullptr) {
}

void Complaint::setComplaintName(const std::string &complaintName) {

	this->complaintName = complaintName;
}

void Complaint::setComplaintedItem(const std::string &complaintedItem) {

	this->complaintedItem = complaintedItem;
}

void Complaint::setDateOfComplaint(const std::string &dateOfComplaint) {

	this->dateOfComplaint = dateOfComplaint;
}

void Complaint::setStatus(const std::string &status) {

	this->status = status;

}

std::string Complaint::getComplaintName() const {

	return this->complaintName;
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