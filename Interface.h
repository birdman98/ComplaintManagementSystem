#pragma once

#include "ListOfComplaints.h"

const int oneCharacter = 1;

class Interface {

	/*const*/ enum choices {addComplaint = 1, searchComplaint, deleteComplaint, changeStatusOfComplaint, displayComplaints, employeesComplaints, exit = 9};

	static int choice;


public:
	Interface();
	//~Interface();

	static void printMenu();
    static void getUsersChoice(int& choice);
	static bool menu(ListOfComplaints &list);
};

