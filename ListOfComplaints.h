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

	int operator() () const; //zwraca ilo�� reklamacji w systemie
	void operator! () const; //wypisuje reklamacje, kt�rych termin rozpatrzenia si� zbli�a
	

	~ListOfComplaints();
};

