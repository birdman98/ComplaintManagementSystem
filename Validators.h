#pragma once
#include <string>

class Validators {

public:

	virtual bool validate(const std::string &toCheck) = 0;
	virtual ~Validators() = default;
};

class ComplaintTitle : public Validators {
	
public:

	bool validate(const std::string &toCheck) override;
};

class ComplaintedItem : public Validators {
	
public:

	bool validate(const std::string &toCheck) override;
};

class IDData : public Validators {
	
public:

	bool validate(const std::string &toCheck) override;
};

class Pesel : public Validators {
	
public:

	bool validate(const std::string &toCheck) override;
};

class Adress : public Validators {
	
public:

	bool validate(const std::string &toCheck) override;
};

class PhoneNumber : public Validators {
	
public:

	bool validate(const std::string &toCheck) override;
};