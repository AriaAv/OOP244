/**********************************************************
// Workshop 3: Classes and Privacy
// Date 2018-05-30
// Author Aria Avazkhani
//
// Revision History
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

	class CRA_Account {

		char fName[max_name_length];
		char gName[max_name_length];
		int sinN;

	public:

		void set(const char *familyName, const char *givenName, int sin) {
			
			if (sin < max_sin && sin > min_sin) {
				strncpy(fName, familyName, sizeof fName);
				strncpy(gName, givenName, sizeof gName);
				sinN = sin;
			}
			else {
				strncpy(fName, " ", 1);
				strncpy(gName, " ", 1);
				sinN = 0;
			}
		}

		bool isEmpty() {
			if (sinN < max_sin && sinN > min_sin) {
				return false;
			}
			else {
				return true;
			}
		}

		void display() {
			if (sinN != 0 && fName != '\0' && gName != '\0') {
				cout << "Family Name: " << fName << endl;
				cout << "Given Name : " << gName << endl;
				cout << "CRA Account: " << sinN << endl;
			}
			else {
				cout << "Account object is empty!" << endl;
			}
		}

	};
}

#endif