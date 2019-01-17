#pragma once

#include "Complaint.h"

class ListOfComplaints {

	Complaint* head;
	Complaint* top;

public: 

	ListOfComplaints();
	ListOfComplaints(Complaint complaint_); 

	Complaint* getHead() const;

	bool operator-(const Complaint* complaintToDelete); //usuwa reklamacje z listy
	bool operator+ (Complaint &complaintToAdd); //dodaje reklamacje do listy //czy tu nie moze byc const??
	Complaint* findComplaint(const std::string &complaintToFind) const;
	void sortComplaintsBy(const int &sortByChoice) const;
	void printComplaints() const;
	void printUnexaminedComplaints() const;
	void printEmployeesComplaints(const std::string &employeesPesel) const;

	int operator() () const; //zwraca iloœæ reklamacji w systemie
	void operator! () const; //wypisuje reklamacje, których termin rozpatrzenia siê zbli¿a
	

	~ListOfComplaints();
};

