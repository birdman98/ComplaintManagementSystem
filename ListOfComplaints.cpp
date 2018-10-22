#include "stdafx.h"
#include "ListOfComplaints.h"
#include <iostream>


ListOfComplaints::ListOfComplaints() :

	head(nullptr),
	top(nullptr) {
}

ListOfComplaints::ListOfComplaints(Complaint complaint_) {

	Complaint* firstElement = new Complaint(complaint_);

	this->head = firstElement;
	this->top = firstElement;
}

bool ListOfComplaints::deleteComplaint(const std::string &complaintToDelete) {

	std::cout<<"Funkcjonalnosc w trakcie budowy\n\n";

	return false;
}

bool ListOfComplaints::addComplaint(Complaint &complaintToAdd) {

	Complaint* toAdd = new Complaint(complaintToAdd); //konstruktor ustawia next i prev na nullptr

	this->top = toAdd; 

	Complaint* current = head;

	while (current->getNext()->getNext() != nullptr) {

		current = current->getNext();
	}

	if (head != nullptr) {

		current->setNext(toAdd);
		toAdd->setPrev(current);

	}
	else {

			this->head = toAdd;
	}
	

	return true;
}

Complaint ListOfComplaints::findComplaint(const std::string &complaintToFind) {

	std::cout << "Funkcjonalnosc w trakcie budowy\n\n";

	return Complaint();
}

void ListOfComplaints::sortComplaintsBy(const int &sortByChoice) {

	std::cout << "Funkcjonalnosc w trakcie budowy\n\n";
}

void ListOfComplaints::printComplaints() {

	Complaint* current = head;

	while (current != nullptr) { //przeci¹¿yæ operatory wypisywania

		std::cout << current->getComplaintName() << "\n" << current->getComplaintedItem() << "\n\n";

		current = current->getNext();
	}

}

ListOfComplaints::~ListOfComplaints() {


}
