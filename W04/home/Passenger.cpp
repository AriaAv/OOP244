// TODO: add file header comments here
/**********************************************************
// Workshop 4
// Date 2018-06-10
// Author Aria Avazkhani
//
**********************************************************/

// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>
#include <iomanip>


using namespace std;
using namespace sict;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		pName[0] = '\0';
		dest[0] = '\0';
		year = 0;
		month = 0;
		day = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *name, const char *des) {
		if (name == nullptr || name[0] == '\0' || des == nullptr || des[0] == '\0')
			Passenger();
		else {
			strncpy(pName, name, sizeof pName-1);
			pName[sizeof pName] = '\0';
			strncpy(dest, des, sizeof dest); 
			dest[sizeof dest] = '\0';
			year = 2017;
			month = 7;
			day = 1;
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (pName[0] == '\0' || dest[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty() == false) {
			cout << pName << " - " << dest << " on " << year << "/" << std::setw(2) << std::setfill('0') << month << "/" << day << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}

	}
	Passenger::Passenger(const char *name, const char *des, const int years,
		const int months, const int days) {
		if (name == nullptr || name[0] == '\0' || des == nullptr || des[0] == '\0'
			|| years > 2020 || years < 2017 || months > 12 || months < 1
			|| days > 31 || days < 1)
			Passenger();
		else {
			strncpy(pName, name, sizeof pName);
			pName[sizeof pName] = '\0';
			strncpy(dest, des, sizeof dest);
			dest[sizeof dest] = '\0';
			year = years;
			month =  months;
			day = days;

		}

	}
	const char *Passenger::name() const {
		if (isEmpty() == false) {
			return pName;
		}
		else {
			return nullptr;
		}
	}
	bool Passenger::canTravelWith(const Passenger& pass) const {
		int i = 0;
		int flag = 0;
		while (pass.dest[i] != '\0'){
			if (pass.dest[i] == dest[i] && pass.year == year && pass.month == month && pass.day == day) {
				flag = 1;
				i++;
			}
			else
				break;
		}
		if (flag == 1)
			return true;
		else
			return false;
	}
}