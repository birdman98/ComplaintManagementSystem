#include "stdafx.h"

#include "filesSupport.h"

#include <fstream>
#include <iostream>
#include <string>
#include "Complaint.h"


filesSupport::filesSupport(const std::string& inFileName, const std::string& outFileName) :
    inFileName(inFileName),
    outFileName(outFileName) {
}

bool filesSupport::saveToFile() const {
	
	std::ofstream outFile;
	
	outFile.open(this->outFileName, std::ofstream::out);

	if(outFile.fail()) {

		std::cerr << "Blad podczas zapisu do pliku: " << strerror(errno);
	}


	outFile.close();

	return true;
	
}

bool filesSupport::readFromFile(ListOfComplaints &list) const {
	
	Complaint complaint;
	Customer customer;
	Employee employee;

	std::string line = "";

	std::ifstream inFile;

	inFile.open(this->inFileName, std::ofstream::in);

	if (inFile.fail()) {

		std::cerr << "Blad podczas otwierania pliku: " << strerror(errno);

		return false;
	}

	while(std::getline(inFile, line)) {

		complaint.setComplaintTitle(line);

		std::getline(inFile, line);
		complaint.setComplaintedItem(line);

		std::getline(inFile, line);
		complaint.setDateOfComplaint(line);

		std::getline(inFile, line);
		complaint.setStatus(line);

		std::getline(inFile, line);
		customer.setName(line);

		std::getline(inFile, line);
		customer.setSurname(line);

		std::getline(inFile, line);
		customer.setAdress(line); 

		std::getline(inFile, line);
		customer.setPhoneNumber(line);

		std::getline(inFile, line);
		customer.setPesel(line);

		std::getline(inFile, line);
		employee.setName(line);

		std::getline(inFile, line);
		employee.setSurname(line);

		std::getline(inFile, line);
		employee.setPesel(line);
		
		complaint.setCustomersData(customer);
		complaint.setEmployeesData(employee);

		list.addComplaint(complaint);

	}

	inFile.close();

	return true;
}
