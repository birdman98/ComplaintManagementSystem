#pragma once

#include "Complaint.h"

class ListOfComplaints {

	Complaint* head;
	Complaint* top;

public: 

	ListOfComplaints();
	ListOfComplaints(Complaint complaint_); 

	Complaint* getHead() const;

	bool deleteComplaint(const Complaint* complaintToDelete);
	bool addComplaint(Complaint &complaintToAdd);
	Complaint* findComplaint(const std::string &complaintToFind) const;
	void sortComplaintsBy(const int &sortByChoice) const;
	void printComplaints() const;
	void printUnexaminedComplaints() const;
	void ListOfComplaints::printComplaintsNearDeadline() const;

	~ListOfComplaints();
};

