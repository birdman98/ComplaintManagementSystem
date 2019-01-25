#pragma once

#include "ListOfComplaints.h"
#include "filesSupport.h"

class Interface {

	static const int invalidInput = 99; //zmienna pomocnicza

	enum choices {addComplaint = 1, searchComplaint, deleteComplaint, changeStatusOfComplaint, displayComplaints, displayComplaintsNearDeadline, displayUnexaminedComplaints, employeesComplaints, exit = 9};

	static int choice;

public:

	Interface();

	static void printMenu(const ListOfComplaints &list);
    static void getUsersChoice(int& choice);
	static bool menu(ListOfComplaints &list, filesSupport &file);
};

enum colors {black, blue, green, red = 4, default_color = 7, important_info = 160}; //kolory dla tekstu w konsoli

void setConsoleColor(const int &color); //funkcja do ustawiania koloru w konsoli

