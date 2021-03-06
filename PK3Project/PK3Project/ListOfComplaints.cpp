#include "stdafx.h"
#include "ListOfComplaints.h"
#include <iostream>

ListOfComplaints::ListOfComplaints() :

	head(nullptr),
	top(nullptr) {
}

ListOfComplaints::ListOfComplaints(const Complaint &complaint) {

	Complaint* firstElement = new Complaint(complaint);

	this->head = firstElement;
	this->top = firstElement;
}

Complaint* ListOfComplaints::getHead() const {
	
	return this->head;
}

bool ListOfComplaints::operator+=(const Complaint &complaintToAdd) {

	if (this->findComplaint(complaintToAdd.getComplaintTitle()) != nullptr) {

		std::cout << "\nReklamacja o podanym tytule juz istnieje!\n\n";

		return false;
	}

	Complaint* toAdd = new Complaint(complaintToAdd);

	if (this->head == nullptr) {

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

bool ListOfComplaints::operator-=(const Complaint* complaintToDelete) { 

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

	bool anyComplaint = false;

	while(current != nullptr) {
		
		if((current->getStatus() == "przyjeta") || (current->getStatus() == "w toku")) {
			
			std::cout << *current;
			std::cout << "\n\n______________________________________________\n\n";

			anyComplaint = true;
		}

		current = current->getNext();
	}

	if(!anyComplaint) {
		
		std::cout << "Aktualnie brak reklamacji oczekujacych na rozpatrzenie.\n\n";
	}
}

void ListOfComplaints::printEmployeesComplaints(const std::string &employeesPesel) const {

	Complaint* current = this->head;
	bool anyComplaint = false;

	Employee employeesData;

	while(current != nullptr) {
		
		employeesData = current->getEmployeesData();

		if(employeesData.getPesel() == employeesPesel) {
			
			std::cout << *current << "\n\n";
			std::cout << "__________________________________________________\n\n";

			anyComplaint = true;
		}

		current = current->getNext();
	}

	if(!anyComplaint) {
		
		std::cout << "Aktualnie w systemie nie ma zadnych obslugiwanych przez ciebie reklamacji.\n\n";
	}
}

int ListOfComplaints::complaintsNearDeadlineCount() const {
	
	Complaint* current = this->head;

	int nearDeadlineCount = 0;
	int duration = 0;

	while (current != nullptr) {

		if (current->checkIfNeedsToBeExamined(duration) && (current->getStatus() == "przyjeta" || current->getStatus() == "w toku")) {

			++nearDeadlineCount;			
		}

		current = current->getNext();
	}

	return nearDeadlineCount;
}

int ListOfComplaints::operator()() const {
	
	Complaint* current = this->head;
	int size = 0;

	while (current != nullptr) {

		++size;

		current = current->getNext();
	}

	return size;
}

void ListOfComplaints::operator!() const {

	Complaint* current = this->head;

	int duration = 0;
	bool anyComplaint = false;

	while (current != nullptr) {

		if (current->checkIfNeedsToBeExamined(duration) && (current->getStatus() == "przyjeta" || current->getStatus() == "w toku")) {

			std::cout << *current;
			std::cout << "\n\nDni, ktore minely od zlozenia reklamacji w (przyblizeniu): " << duration << "\n\n";
			std::cout << "_____________________________________________________________________\n\n";

			anyComplaint = true;
		}

		current = current->getNext();

	}

	if (!anyComplaint) {

		std::cout << "Aktualnie termin rozpatrzenia zadnej z reklamacji sie nie zbliza.\n\n";
	}

}

ListOfComplaints::~ListOfComplaints() {

	Complaint* toDelete = this->head; 

	while(toDelete != nullptr) {
		
		head = head->getNext();

		delete toDelete;

		toDelete = head;
	}

	this->head = nullptr;
	this->top = nullptr;
}
