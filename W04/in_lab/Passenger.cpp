// TODO: add file header comments here
/**********************************************************
// Workshop 3: Classes and Privacy
// Date 2018-06-04
// Author Aria Avazkhani
//
**********************************************************/

// TODO: add your headers here
#include <iostream>
#include "Passenger.h"
#include <cstring>


using namespace std;
using namespace sict;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		strncpy(pName, "\0", sizeof pName);
		strncpy(dest, "\0", sizeof dest);
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *name, const char *des) {
		if (name == nullptr|| name[0] == '\0' || des == nullptr || des[0] == '\0')
			Passenger();
		else {
			strncpy(pName, name, sizeof pName);
			strncpy(dest, des, sizeof dest);
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (pName[0] == '\0' && dest[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty() == false) {
			cout << pName << " - " << dest << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}

	}
}