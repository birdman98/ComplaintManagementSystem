#include "stdafx.h"
#include "Interface.h"

#include <string>
#include <iostream>

int Interface::choice = 0;


Interface::Interface()
{
	choice = 0;
}


//Interface::~Interface() {
//}

void Interface::printMenu() {

	std::cout << "*******************************************************************************\n";
	std::cout << "**                                                                           **\n";
	std::cout << "** 1. Dodaj reklamacje                                                       **\n";
	std::cout << "** 2. Wyszukaj reklamacje                                                    **\n";
	std::cout << "** 3. Usun wybrana reklamacje                                                **\n";
	std::cout << "** 9. Wyjdz.                                                                 **\n";
	std::cout << "**                                                                           **\n";
	std::cout << "*******************************************************************************\n";

}

void Interface::getUsersChoice(int& choice) {

	std::cout << "Podaj swoj wybor: ";
	std::cin >> choice; //exception na coœ innego ni¿ int

}

 bool Interface::menu() 
 {
	 printMenu();

	 getUsersChoice(choice);

	 switch (choice) {

	 case addComplaint: {

	//	 addComplaint();

			 break;
		 }
	 case searchComplaint: {

		// SearchComplaint();

		 break;
	 }

	 case deleteComplaint: {

		// DeleteComplaint();

		 break;
	 }

	 case employeesComplaints: {

		// employeesComplaints();

		 break;
	 }
	 case exit: {

		 std::cout<<"Trwa zamykanie programu....\n\n";

		 //saveFromListToFile();


		 return false;

		// break;
	 }

	 default: {

	 std::cout << "Niepoprawny wybor, sprobuj ponownie.\n\n";
	 }

	 }

	 return true;
 }
