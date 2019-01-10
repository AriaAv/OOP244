// Final Project Milestone 2
//
// Version 1.0
// 2018-07-23
// Aria Avazkhani
//
/////////////////////////////////////////////////////////////////
#include "ErrorState.h"

namespace AMA {

	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr)
			err = nullptr;
		else {
			err = new char[strlen(errorMessage) + 1];
			strncpy(err, errorMessage, strlen(errorMessage));
			err[strlen(errorMessage)] = '\0';
		}
	}
	ErrorState::~ErrorState() {
		delete[] err;
		err = nullptr;
	}
	void ErrorState::clear() {
		err = nullptr;
	}
	bool ErrorState::isClear() const{
		if (err == nullptr)
			return true;
		else
			return false;
	}
	void ErrorState::message(const char* str) {
		delete[] err;
		err = new char[strlen(str) + 1];
		strncpy(err, str, strlen(str));
		err[strlen(str)] = '\0';
	}
	const char* ErrorState::message() const {
		return err;
	}
	std::ostream& operator<<(std::ostream& os,const ErrorState& obj) {
		if (obj.isClear() != true)
			os << obj.message();
		return os;
	}
}