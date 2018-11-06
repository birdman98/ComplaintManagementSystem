#pragma once

#include "Customer.h"
#include "Employee.h"

#include <string>

class Complaint {

	std::string complaintName;
	std::string complaintedItem;
	Customer customersData; //ale przy wyœwietlaniu ju¿ po ID
	Employee employeesData; //tak samo
	std::string dateOfComplaint;
	int duration; //czas miniony od podjêcia reklamacji, volatile??, czy to pole tu potrzebne czy lepiej metode, ktora na biezaco to wyliczy?
	std::string status; //status wybierany z menu, nie wpisywany z palca!

	Complaint* next;
	Complaint* prev;

public:

	Complaint();
	Complaint(const Complaint &complaint);
	//Complaint() jeszcze konstruktor wieloargumentowy

	void setComplaintName(const std::string &complaintName);
	void setComplaintedItem(const std::string &complaintedItem);
	void setDateOfComplaint(const std::string &dateOfComplaint);
	void setStatus(const std::string &status);

	std::string getComplaintName() const;
	std::string getComplaintedItem() const;
	std::string getDateOfComplaint() const;
	int getDuration() const;
	std::string getStatus() const;

	Complaint* getNext() const;
	Complaint* getPrev() const;

	void setNext(Complaint* nextToSet);
	void setPrev(Complaint* prevToSet);

	~Complaint(); //potrzebny akurat tutaj??
};

