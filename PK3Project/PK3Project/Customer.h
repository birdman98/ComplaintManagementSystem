#pragma once

#include <string>
#include <istream>
#include <ostream>

class Customer {

	std::string name;
	std::string surname;
	std::string adress;
	std::string phoneNumber;
	std::string pesel;

public:
	
	Customer() = default;

	void setName(const std::string &name);
	void setSurname(const std::string &surname);
	void setAdress(const std::string &adress);
	void setPhoneNumber(const std::string &phoneNumber);
	void setPesel(const std::string &pesel);

	std::string getName() const;
	std::string getSurname() const;
	std::string getAdress() const;
	std::string getPhoneNumber() const;
	std::string getPesel() const;

	friend std::istream& operator>>(std::istream &input, Customer &toFill);
	friend std::ostream& operator<<(std::ostream &output, const Customer &toPrint);

};

