#include "stdafx.h"
#include "ListOfComplaints.h"
#include <iostream>

//TODO:
//dodaæ wypisywanie wszystkich reklamacji, które nie zosta³y jeszcze rozpatrzone
//przy starcie programu przypominaæ, ¿e siê koñczy czas na rozpatrzenie jakiejœ reklamacji
//inicjalizacja pola daty aktualn¹ dat¹ systemow¹
//przeci¹¿yæ operator wypisywania

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

	Complaint* current = head;
	Complaint* prev = nullptr;
	Complaint* next = nullptr;


	while ((current != nullptr) && (current->getComplaintName() != complaintToDelete)) {

		current = current->getNext();
	}

	if (current == nullptr) {

		std::cout << "Podana reklamacja nie istnieje!\n\n";

		return false;
	}

	if(current == head) {

		delete current;

		head = nullptr;
		top = nullptr;

		return true;
	}

	prev = current->getPrev(); 
	next = current->getNext();

	prev->setNext(next);
	next->setPrev(prev);

	delete current;

	std::cout << "\nUsunieto reklamacje o tytule " << complaintToDelete << "\n\n";

	return true;
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

	Complaint* current = head;

	while((current != nullptr) && (current->getComplaintName() != complaintToFind)) {

		current = current->getNext();		
	}

	if(current==nullptr) {

		std::cout << "\nReklamacja " << complaintToFind << " nie istnieje!\n\n";

		return Complaint();
		
	}
	

	return *current;
}

void ListOfComplaints::sortComplaintsBy(const int &sortByChoice) {

	std::cout << "Funkcjonalnosc w trakcie budowy\n\n";
}

void ListOfComplaints::printComplaints() {

	Complaint* current = head;

	if(current == nullptr) {

		std::cout << "Lista reklamacji jest pusta!\n";
		

	}

	while (current != nullptr) { 

		std::cout << current->getComplaintName() << "\n" << current->getComplaintedItem() << "\n\n";

		current = current->getNext();
	}

}

ListOfComplaints::~ListOfComplaints() {


}
