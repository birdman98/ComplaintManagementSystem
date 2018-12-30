#pragma once
#include <string>


class DataGuard {

	static const int encryptionKey = 94;
	static const int maxASCIIValue = 255;
	static const int minASCIIValue = 0;

public:

	static std::string encryptData(const std::string &toEncrypt);
	static std::string decryptData(const std::string &toDecrypt);


};
