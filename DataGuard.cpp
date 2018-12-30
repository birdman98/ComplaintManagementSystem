#include "DataGuard.h"

std::string DataGuard::encryptData(const std::string &toEncrypt) { 
	
	std::string encryptedData = "";

	int encryptedASCII = 0;

	for(int i = 0; i < toEncrypt.length(); ++i) {
		
		encryptedASCII = toEncrypt[i] + encryptionKey;

		if(encryptedASCII <= maxASCIIValue) {

			encryptedData += encryptedASCII;
		}
		else {
			
			encryptedData += encryptedASCII % maxASCIIValue - 1; 		
		}
		
	}

	return encryptedData;
}

std::string DataGuard::decryptData(const std::string &toDecrypt) {
	

	std::string decryptedData = "";
	int decryptedASCII = 0;

	for (int i = 0; i < toDecrypt.length(); ++i) {

		decryptedASCII = toDecrypt[i] - encryptionKey;

		if(decryptedASCII >= minASCIIValue) {
			
			decryptedData += decryptedASCII;
		} else {
			
			decryptedData += maxASCIIValue + decryptedASCII + 1;
		}
		 

	}

	return decryptedData;
}
