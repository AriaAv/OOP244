// Final Project Milestone 2
//
// Version 1.0
// 2018-07-23
// Aria Avazkhani
//
/////////////////////////////////////////////////////////////////
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>
#include <cstring>
using namespace std;

namespace AMA {

	class ErrorState {

		char *err;

	public:

		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator= (const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message (const char*);
		const char* message() const;

	};
	std::ostream& operator<<(std::ostream&,const ErrorState&);
}

#endif