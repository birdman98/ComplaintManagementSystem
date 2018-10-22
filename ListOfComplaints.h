#pragma once

#include "Complaint.h"

class ListOfComplaints {

	Complaint* head;
	Complaint* top;

public: //jak inicjalizowaæ pierwszy element (najlepiej ¿eby by³ nie pusty!)

	ListOfComplaints();
	ListOfComplaints(Complaint complaint_); //czy nie lepiej konstruktor przenosz¹cy? lub kopiuj¹cy lub operator przeniesienia?

	bool deleteComplaint(const std::string &complaintToDelete);
	bool addComplaint(Complaint &complaintToAdd);
	Complaint findComplaint(const std::string &complaintToFind);
	void sortComplaintsBy(const int &sortByChoice);
	void printComplaints();

	~ListOfComplaints();
};

