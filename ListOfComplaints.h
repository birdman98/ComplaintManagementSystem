#pragma once

#include "Complaint.h"

class ListOfComplaints {

	Complaint* head;
	Complaint* top;

public: 

	ListOfComplaints();
	ListOfComplaints(Complaint complaint_); 

	bool deleteComplaint(const std::string &complaintToDelete);
	bool addComplaint(Complaint &complaintToAdd);
	Complaint findComplaint(const std::string &complaintToFind);
	void sortComplaintsBy(const int &sortByChoice);
	void printComplaints();

	~ListOfComplaints();
};

