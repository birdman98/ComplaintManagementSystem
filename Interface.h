#pragma once

#include "ListOfComplaints.h"
#include <Windows.h>

const int invalidInput = 99;

class Interface {

	enum choices {addComplaint = 1, searchComplaint, deleteComplaint, changeStatusOfComplaint, displayComplaints, displayComplaintsNearDeadline, displayUnexaminedComplaints, employeesComplaints, exit = 9};

	static int choice;


public:
	Interface();
	//~Interface();

	static void printMenu(const ListOfComplaints &list);
    static void getUsersChoice(int& choice);
	static bool menu(ListOfComplaints &list);
};

enum colors {black, blue, green, red = 4, default_color = 7, important_info = 160};

void setConsoleColor(const int &color);

