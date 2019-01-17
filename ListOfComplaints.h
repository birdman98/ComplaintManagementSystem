#pragma once

#include "Complaint.h"

class ListOfComplaints {

	Complaint* head;
	Complaint* top;

public: 

	ListOfComplaints();
	ListOfComplaints(const Complaint &complaint); 

	Complaint* getHead() const;

	bool operator+ (const Complaint &complaintToAdd); //dodaje reklamacje do listy 
	bool operator-(const Complaint* complaintToDelete); //usuwa reklamacje z listy
	
	Complaint* findComplaint(const std::string &complaintToFind) const;
	void printComplaints() const;
	void printUnexaminedComplaints() const;
	void printEmployeesComplaints(const std::string &employeesPesel) const;

	int operator() () const; //zwraca iloœæ reklamacji w systemie
	void operator! () const; //wypisuje reklamacje, których termin rozpatrzenia siê zbli¿a
	

	~ListOfComplaints();
};

