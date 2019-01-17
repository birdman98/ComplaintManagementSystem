#pragma once

#include "Customer.h"
#include "Employee.h"

#include <string>
#include <ostream>
#include <istream>

const int almostDeadline = 14;

class Complaint {

	std::string complaintTitle;
	std::string complaintedItem;
	std::string dateOfComplaint;
	std::string status;

	Customer customersData; 
	Employee employeesData;

	Complaint* next;
	Complaint* prev;

public:

	Complaint();
	Complaint(const Complaint &complaint);

	void setComplaintTitle(const std::string &complaintTitle); 
	void setComplaintedItem(const std::string &complaintedItem);
	void setDateOfComplaint(const std::string &date = "auto");
	void setStatus(const int &statusChoice);
	void setStatus(const std::string &status);
	void setCustomersData(const Customer &customersData);
	void setEmployeesData(const Employee &employeesData);
	void setNext(Complaint* nextToSet);
	void setPrev(Complaint* prevToSet);

	std::string getComplaintTitle() const;
	std::string getComplaintedItem() const;
	std::string getDateOfComplaint() const;
	std::string getStatus() const;
	Customer getCustomersData() const;
	Employee getEmployeesData() const;
	Complaint* getNext() const;
	Complaint* getPrev() const;

	bool checkIfNeedsToBeExamined(int &durationInDays) const; 	

	friend std::istream& operator>>(std::istream &input, Complaint &toFill);
	friend std::ostream& operator<<(std::ostream &output, const Complaint &toPrint);

};

enum possibleStatuses { accepted = 1, processing, consideredPositive, consideredNegative, rejected };

