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
	bool operator+ (Complaint &complaintToAdd); //dodaje reklamacje do listy
	Complaint* findComplaint(const std::string &complaintToFind) const;
	void sortComplaintsBy(const int &sortByChoice) const;
	void printComplaints() const;
	void printUnexaminedComplaints() const;
	void printEmployeesComplaints(const std::string &employeesPesel) const;

	int operator() () const; //zwraca ilo�� reklamacji w systemie
	void operator! () const; //wypisuje reklamacje, kt�rych termin rozpatrzenia si� zbli�a
	

	~ListOfComplaints();
};

