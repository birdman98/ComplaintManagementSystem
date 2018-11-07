#pragma once

#include "Customer.h"
#include "Employee.h"

#include <string>
#include <ostream>
#include <istream>

class Complaint {

	std::string complaintTitle;
	std::string complaintedItem;
	Customer customersData; //ale przy wyœwietlaniu ju¿ po ID
	Employee employeesData; //tak samo
	std::string dateOfComplaint;
	std::string status; //status wybierany z menu, nie wpisywany z palca!

	Complaint* next;
	Complaint* prev;

public:

	Complaint();
	Complaint(const Complaint &complaint);
	//Complaint() jeszcze konstruktor wieloargumentowy

	void setComplaintTitle(const std::string &complaintTitle);
	void setComplaintedItem(const std::string &complaintedItem);
	void setDateOfComplaint();
	void setStatus(const std::string &status);

	std::string getComplaintName() const;
	std::string getComplaintedItem() const;
	std::string getDateOfComplaint() const;
	int getDuration() const; //typ zwracany??
	std::string getStatus() const;

	Complaint* getNext() const;
	Complaint* getPrev() const;

	void setNext(Complaint* nextToSet);
	void setPrev(Complaint* prevToSet);

	friend std::istream& operator>>(std::istream& input, Complaint &toFill);
	friend std::ostream& operator<<(std::ostream& output, Complaint &toPrint);

	~Complaint(); //potrzebny akurat tutaj??
};

