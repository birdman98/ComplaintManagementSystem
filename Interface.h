#pragma once
class Interface {

	/*const*/ enum choices {addComplaint = 1, searchComplaint, deleteComplaint, employeesComplaints, exit = 9};

	static int choice;


public:
	Interface();
	//~Interface();

	static void printMenu();
    static void getUsersChoice(int& choice);
	static bool menu();
};

