#include "stdafx.h"

#include "filesSupport.h"

#include <fstream>
#include <iostream>
#include <string>
#include "Complaint.h"
#include "DataGuard.h"

filesSupport::filesSupport(const std::string &inFileName, const std::string &outFileName) :
    
    inFileName(inFileName),
    outFileName(outFileName) {
}

bool filesSupport::saveToFile(ListOfComplaints &list) const {
	
	Complaint* current = list.getHead();

	std::ofstream outFile;
	
	outFile.open(this->outFileName, std::ofstream::out);

	if(outFile.fail()) {

		std::cerr << "Blad podczas zapisu do pliku: " << strerror(errno);

		return false;
	}

	while(current != nullptr) { 

		outFile << current;		
				
		current = current->getNext();
	}
	
	outFile.close();

	return true;
	
}

bool filesSupport::readFromFile(ListOfComplaints &list) const {
	
	Complaint complaint;

	std::ifstream inFile;

	inFile.open(this->inFileName, std::ofstream::in);

	if (inFile.fail()) {

		std::cerr << "Blad podczas otwierania pliku: " << strerror(errno);

		return false;
	}

	while(inFile >> complaint) {		

		list += complaint;
	}

	inFile.close();

	return true;
}

std::ofstream& operator<<(std::ofstream &outFile, const Complaint* current) {

	Customer customersData;
	Employee employeesData;

	outFile << current->getComplaintTitle() << "\n";
	outFile << current->getComplaintedItem() << "\n";
	outFile << current->getDateOfComplaint() << "\n";
	outFile << current->getStatus() << "\n";

	customersData = current->getCustomersData();

	outFile << customersData.getName() << "\n";
	outFile << customersData.getSurname() << "\n";
	outFile << DataGuard::encryptData(customersData.getAdress()) << "\n";
	outFile << DataGuard::encryptData(customersData.getPhoneNumber()) << "\n";
	outFile << DataGuard::encryptData(customersData.getPesel()) << "\n";

	employeesData = current->getEmployeesData();

	outFile << employeesData.getName() << "\n";
	outFile << employeesData.getSurname() << "\n";
	outFile << DataGuard::encryptData(employeesData.getPesel()) << "\n";

	return outFile;
}

std::ifstream& operator>>(std::ifstream &inFile, Complaint &complaint) {

	Customer customersData;
	Employee employeesData;

	std::string line = "";

	std::getline(inFile, line);
	complaint.setComplaintTitle(line);

	std::getline(inFile, line);
	complaint.setComplaintedItem(line);

	std::getline(inFile, line);
	complaint.setDateOfComplaint(line);

	std::getline(inFile, line);
	complaint.setStatus(line);

	std::getline(inFile, line);
	customersData.setName(line);

	std::getline(inFile, line);
	customersData.setSurname(line);

	std::getline(inFile, line);
	customersData.setAdress(DataGuard::decryptData(line));

	std::getline(inFile, line);
	customersData.setPhoneNumber(DataGuard::decryptData(line));

	std::getline(inFile, line);
	customersData.setPesel(DataGuard::decryptData(line));

	std::getline(inFile, line);
	employeesData.setName(line);

	std::getline(inFile, line);
	employeesData.setSurname(line);

	std::getline(inFile, line);
	employeesData.setPesel(DataGuard::decryptData(line));

	complaint.setCustomersData(customersData);
	complaint.setEmployeesData(employeesData);	

	return inFile;
}
