#include "stdafx.h"
#include "Interface.h"
#include "Complaint.h"

#include <string>
#include <iostream>
#include <Windows.h>
#include <limits>

int Interface::choice = 0;


Interface::Interface() {

	Interface::choice = 0;
}

void Interface::printMenu() {

	std::cout << "*******************************************************************************\n";
	std::cout << "**                                                                           **\n";
	std::cout << "** 1. Dodaj reklamacje                                                       **\n";
	std::cout << "** 2. Wyszukaj reklamacje                                                    **\n";
	std::cout << "** 3. Usun wybrana reklamacje                                                **\n";
	std::cout << "** 4. Zmien status wybranej reklamacji                                       **\n";
	std::cout << "** 5. Wyswietl wszystkie reklamacje w systemie                               **\n";
	std::cout << "** 9. Wyjdz.                                                                 **\n";
	std::cout << "**                                                                           **\n";
	std::cout << "*******************************************************************************\n";

}

void Interface::getUsersChoice(int& choice) {
	
		std::cout << "Podaj swoj wybor: ";

	    if(std::cin >> choice) {
		    
	    }
		else {

			std::cin.clear();

			choice = invalidInput;

	    }
			

	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

}

 bool Interface::menu(ListOfComplaints &list) {

	 system("cls");

	 printMenu();


	getUsersChoice(choice);

	 switch (choice) {

	 case addComplaint: {

		 system("cls"); 

		 std::cout << "MODUL DODAWANIA REKLAMACJI.\n________________________________________________________\n\n";

		 Complaint usersComplaint;

		 std::cin >> usersComplaint;

		 usersComplaint.setDateOfComplaint();
		 usersComplaint.setStatus(accepted);

	     if (list.addComplaint(usersComplaint)) {
		     
			 std::cout << "\nDodano reklamacje.\n\n";
	     }
		 else {
			 
			 std::cout << "\nWystapil blad podczas dodawania reklamacji.\n\n";
		 }

		 system("pause");

			 break;
		 }

	 case searchComplaint: {

		 system("cls");

		 std::string toFindTitle = "";

		 std::cout << "Podaj tytul reklamacji do znalezienia w systemie: ";
		 std::getline(std::cin, toFindTitle);

		 Complaint* foundComplaint = list.findComplaint(toFindTitle);

		 if(foundComplaint) {
			 
			 std::cout << *foundComplaint << "\n\n";
		 }
		 else {
			 
			 std::cout << "Nie znaleziono podanej reklamacji.\n\n";
		 }

		
		 system("pause");

		 break;
	 }	

	 case deleteComplaint: {

		 std::string toDeleteTitle = "";

		 std::cout << "Podaj tytul reklamacji do usuniecia: ";
		 std::getline(std::cin, toDeleteTitle);

		 Complaint* toDelete = list.findComplaint(toDeleteTitle);

		 if (list.deleteComplaint(toDelete)) {

			 std::cout << "\nUsunieto reklamacje o tytule " << toDeleteTitle << "\n\n";

		 }
		 else {
			 
			 std::cout << "\nNie udalo sie usunac zadanej reklamacji!\n\n";
		 }
		  

		 system("pause");

		 break;
	 }

	 case changeStatusOfComplaint: {

		 system("cls");

		 std::string toChangeTitle;

		 std::cout << "Podaj tytul reklamacji, ktorej status chcesz zmienic: ";
		 std::getline(std::cin, toChangeTitle);

		 Complaint* complaintToChange = list.findComplaint(toChangeTitle);

		 if (complaintToChange) {

			 int statusChoice = 0;

			 std::cout << "Obecny status reklamacji o tytule: " << complaintToChange->getComplaintTitle() << " : " << complaintToChange->getStatus() << "\n\n";

			 std::cout << "Wybierz na jaki status chcesz zmienic obecny status reklamacji:\n";
			 std::cout << "1. Przyjeta,\n2. W toku,\n3. Rozpatrzona pozytywnie,\n4. Rozpatrzona negatywnie,\n5. Odrzucona.\n\n";

			 Interface::getUsersChoice(statusChoice);

			 if (statusChoice >= 1 && statusChoice <= 5) {

				 complaintToChange->setStatus(statusChoice);

				 std::cout << "Status zostal zmieniony poprawnie.\n\n";
			 }
			 else {

				 std::cout << "Nie udalo sie zmienic statusu podanej reklamacji.\nNieprawidlowy wybor statusu.\n\n";
			 }
		 }

		 system("pause");
		 
		 break;
	 }
	 case displayComplaints: {
		 
		 system("cls");

		 list.printComplaints();

		 system("pause");

		 break;
	 }

	 case employeesComplaints: {

		// employeesComplaints();

		 system("pause");

		 break;
	 }
	 case exit: {

		 std::cout<<"Trwa zamykanie programu....\n\n";

		 return false;

	 }

	 default: {

	 std::cout << "\n\nNiepoprawny wybor, sprobuj ponownie.\n\n";

	 system("pause");

	 }

	 }

	 return true;
 }
