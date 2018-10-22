#pragma once

#include "Complaint.h"

class ListOfComplaints {

	Complaint* head;
	Complaint* top;

public: //jak inicjalizowa� pierwszy element (najlepiej �eby by� nie pusty!)

	ListOfComplaints();
	ListOfComplaints(Complaint complaint_); //czy nie lepiej konstruktor przenosz�cy? lub kopiuj�cy lub operator przeniesienia?

	bool deleteComplaint(const std::string &complaintToDelete);
	bool addComplaint(Complaint &complaintToAdd);
	Complaint findComplaint(const std::string &complaintToFind);
	void sortComplaintsBy(const int &sortByChoice);
	void printComplaints();

	~ListOfComplaints();
};

