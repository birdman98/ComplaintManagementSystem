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

	void setComplaintTitle(const std::string &complaintTitle); //te sety s¹ w sumie zbedne, skoro mam operator, jedynie set dla statusu - w interface zrobic menu do tego
	void setComplaintedItem(const std::string &complaintedItem);
	void setDateOfComplaint();
	void setStatus(const int &statusChoice);

	std::string getComplaintTitle() const;
	std::string getComplaintedItem() const;
	std::string getDateOfComplaint() const;
	int getDuration() const; //typ zwracany??
	std::string getStatus() const;

	Complaint* getNext() const;
	Complaint* getPrev() const;

	void setNext(Complaint* nextToSet);
	void setPrev(Complaint* prevToSet);

	friend std::istream& operator>>(std::istream& input, Complaint &toFill);
	friend std::ostream& operator<<(std::ostream& output, const Complaint &toPrint);

	~Complaint(); //potrzebny akurat tutaj??
};

enum possibleStatuses { accepted = 1, processing, consideredPositive, consideredNegative, rejected };
