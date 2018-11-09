#pragma once

#include "ListOfComplaints.h"

const int invalidInput = 99;

class Interface {

	enum choices {addComplaint = 1, searchComplaint, deleteComplaint, changeStatusOfComplaint, displayComplaints, employeesComplaints, exit = 9};

	static int choice;


public:
	Interface();
	//~Interface();

	static void printMenu();
    static void getUsersChoice(int& choice);
	static bool menu(ListOfComplaints &list);
};

