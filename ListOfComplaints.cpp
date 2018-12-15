#include "stdafx.h"
#include "ListOfComplaints.h"
#include <iostream>

//TODO:
//dodaæ wypisywanie wszystkich reklamacji, które nie zosta³y jeszcze rozpatrzone
//przy starcie programu przypominaæ, ¿e siê koñczy czas na rozpatrzenie jakiejœ reklamacji
//dodaæ metodê zwracaj¹c¹ iloœæ reklamacji oczekuj¹cych na rozpatrzenie w systemie i ew. zwi¹zane z tym pole statyczne

ListOfComplaints::ListOfComplaints() :

	head(nullptr),
	top(nullptr) {
}

ListOfComplaints::ListOfComplaints(Complaint complaint_) {

	Complaint* firstElement = new Complaint(complaint_);

	this->head = firstElement;
	this->top = firstElement;
}

bool ListOfComplaints::deleteComplaint(const Complaint* complaintToDelete) { 

	Complaint* prev = nullptr;
	Complaint* next = nullptr;

	if(this->head == nullptr) {
		
		std::cout << "Brak reklamacji w systemie.\n\n";

		return false;
	}

	if (complaintToDelete == nullptr) {

		std::cout << "\nNie mozna usunac zadanej reklamacji - reklamacja nie istnieje!\n\n";

		return false;
	}

	if(complaintToDelete == this->head) {
		
		this->head = this->head->getNext();
	}

	if (complaintToDelete == this->top) {

		this->top = this->top->getPrev();
	}

	prev = complaintToDelete->getPrev();
	next = complaintToDelete->getNext();
		
	if(prev != nullptr) {
		
		prev->setNext(next);
	}

	if (next != nullptr) {

		next->setPrev(prev);
	}


	delete complaintToDelete;

	return true;
}

bool ListOfComplaints::addComplaint(Complaint &complaintToAdd) {

	if(this->findComplaint(complaintToAdd.getComplaintTitle()) != nullptr) {
		
		std::cout << "\nReklamacja o podanym tytule juz istnieje!\n\n";

		return false;
	}

	Complaint* toAdd = new Complaint(complaintToAdd); 

	if(this->head == nullptr) {
		
		this->head = toAdd;
		this->top = this->head;

		return true;
	}

	Complaint* current = this->top;

	current->setNext(toAdd);
	toAdd->setPrev(current);
	this->top = toAdd;

	return true;
}

Complaint* ListOfComplaints::findComplaint(const std::string &complaintToFind) const {

	Complaint* current = head;

	while((current != nullptr) && (current->getComplaintTitle() != complaintToFind)) {

		current = current->getNext();		
	}

	if(current == nullptr) {

		return nullptr;		
	}
	

	return current;
}

void ListOfComplaints::sortComplaintsBy(const int &sortByChoice) const {

	std::cout << "Funkcjonalnosc w trakcie budowy\n\n";
}

void ListOfComplaints::printComplaints() const {

	Complaint* current = head;

	if(current == nullptr) {

		std::cout << "Lista reklamacji jest pusta!\n";
		

	}

	while (current != nullptr) { 

		std::cout << *current << "\n____________________________________________\n";

		current = current->getNext();
	}

}

void ListOfComplaints::printUnexaminedComplaints() const {

	Complaint* current = this->head;

	while(current != nullptr) {
		
		if((current->getStatus() == "zgloszone") || (current->getStatus() == "w toku")) {
			
			//std::cout << *current << "\n____________________________\n";
		}

		current = current->getNext();
	}
}


ListOfComplaints::~ListOfComplaints() {

	Complaint* toDelete = this->head; //zabezpieczenie przed pust¹ list¹?

	while(toDelete != nullptr) {
		
		head = head->getNext();

		delete toDelete;

		toDelete = head;
	}


}
