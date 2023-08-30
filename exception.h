#pragma once
#include <stdexcept>

class customException : public std::exception {
private:
	const char* errorMessage;
public:
	customException(const char* _errorMessage) : errorMessage(_errorMessage) { }
	const char* what() {
		return this->errorMessage;
	}
};
