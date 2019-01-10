/**********************************************************
// Workshop 3: Classes and Privacy
// Date 2018-06-04
// Author Aria Avazkhani
//
// Revision History
**********************************************************/

#include <iostream>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

namespace sict {

	void CRA_Account::set(int year, double balance) {
		if (isEmpty() == false && sinN != 0) {
			
			taxYear[yearsN] = year;
			bal[yearsN] = balance;
			yearsN++;
		}
	}

	void CRA_Account::set(const char *familyName, const char *givenName, int sin) {
		int sinNarr[9];
		int sum = 0;
		int diff = 0;
		int check = 0;
		if (sin < max_sin && sin > min_sin) {
			int sintemp = sin;
			for (int i = 8; i >= 0; i--) {
				sinNarr[i] = sintemp % 10;
				sintemp /= 10;
			}
			for (int i = 1; i <= 7; i += 2) {
				if (2 * sinNarr[i] >= 10) {
					int sinNarrt = sinNarr[i] * 2;
					int sinNarrdo[2];
					for (int i = 1; i >= 0; i--) {
						sinNarrdo[i] = sinNarrt % 10;
						sinNarrt /= 10;
					}
					for (int j = 0; j < 2; j++) {
						sum += sinNarrdo[j];
					}
				}
				else {
					sum += 2 * sinNarr[i];
				}
			}
			for (int i = 0; i <= 6; i += 2) {
				sum += sinNarr[i];
			}
			diff = 10 - (sum % 10);
			if (diff == sinNarr[8]) {
				check = 1;
			}
			if (check == 0 || sin < min_sin || sin > max_sin) {
				strncpy(fName, "\0", 1);
				strncpy(gName, "\0", 1);
				sinN = 0;
			}
			else {
				strncpy(fName, familyName, sizeof fName);
				strncpy(gName, givenName, sizeof gName);
				sinN = sin;
				yearsN = 0;
				for (int i = 0; 1 > max_name_length; i++) {
					if (fName[i] > max_name_length) {
						fName[i - 1] = '\0';
					}
				}

			}
		}
	}

	bool CRA_Account::isEmpty() const{
		if (sinN < min_sin || sinN > max_sin || fName[0] == '\0' || gName[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	void CRA_Account::display() const{
		if (isEmpty() == false) {
			cout << "Family Name: " << fName << endl;
			cout << "Given Name : " << gName << endl;
			cout << "CRA Account: " << sinN << endl;

			for (int i = 0; i < max_yrs; i++) {
				if (bal[i] > 2) {
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << "Year (" << taxYear[i] << ") balance owing: " << bal[i] << endl;
				}
				else if (bal[i] < -2){
					cout << "Year (" << taxYear[i] << ") refund due: "  << bal[i] * -1 << endl;
			}
				else {
					cout << "Year (" << taxYear[i] << ") No balance owing or refund due!" << endl;
				}
			}
			cout.unsetf(ios::fixed);
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}



}