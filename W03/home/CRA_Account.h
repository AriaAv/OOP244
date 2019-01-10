/**********************************************************
// Workshop 3: Classes and Privacy
// Date 2018-06-04
// Author Aria Avazkhani
//
**********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

#include <iostream>
#include <cstring>


using namespace std;

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {

		char fName[max_name_length];
		char gName[max_name_length];
		int sinN = 0;
		int taxYear[max_yrs];
		double bal[max_yrs];
		int yearsN;

	public:

		void set(int year, double balance);
		void set(const char *familyName, const char *givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}

#endif