#include "stdafx.h"
#include "Interface.h"
#include "Complaint.h"

#include <string>
#include <iostream>
#include <Windows.h>

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
	std::cout << "** 4. Zmien status wybranej reklamacji                                       **\n";
	std::cout << "** 9. Wyjdz.                                                                 **\n";
	std::cout << "**                                                                           **\n";
	std::cout << "*******************************************************************************\n";

}

void Interface::getUsersChoice(int& choice) {

	char ws = 0;

	std::cout << "Podaj swoj wybor: ";
	std::cin >> choice >> ws; //exception na coœ innego ni¿ int

}

 bool Interface::menu(ListOfComplaints &list) {

	 system("cls");

	 printMenu();

	 std::cin.clear();
	 std::cin.sync();

	 getUsersChoice(choice);

	 switch (choice) {

	 case addComplaint: {

		 system("cls"); //³apie mi enter ze strumienia! - mo¿e getline na choice

		 std::cout << "Modul dodawania reklamacji.\n\n";

		 Complaint usersComplaint;

		 std::cin >> usersComplaint;

		 usersComplaint.setDateOfComplaint();	

	     list.addComplaint(usersComplaint);

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

	 case changeStatusOfComplaint: {

		 std::string toChangeTitle;

		 std::cout << "Podaj tytul reklamacji, ktorej status chcesz zmienic: ";
		 std::getline(std::cin, toChangeTitle);

		 Complaint* complaintToChange = list.findComplaint(toChangeTitle);

		 if(complaintToChange) {

			 int statusChoice = 0;

			 std::cout << "Obecny status reklamacji o tytule: " << complaintToChange->getComplaintTitle() << " : " << complaintToChange->getStatus() << "\n\n";

			 std::cout << "Wybierz na jaki status chcesz zmienic obecny status reklamacji:\n";
			 std::cout << "1. Przyjeta,\n2. W toku,\n3.Rozpatrzona pozytywnie,\n4. Rozpatrzona negatywnie,\n5. Odrzucona.\n\n";

			 std::cout << "Twoj wybor: ";
			 std::cin >> statusChoice;

			 complaintToChange->setStatus(statusChoice);

			 std::cout << "Status zostal zmieniony poprawnie.\n\n";
			 

		 }
		 else {
			 
			std::cout << "Nie udalo sie zmienic statusu podanej reklamacji.\n\n";
		 }


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
