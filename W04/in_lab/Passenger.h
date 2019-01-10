// TODO: add file header comments here
/**********************************************************
// Workshop 3: Classes and Privacy
// Date 2018-06-04
// Author Aria Avazkhani
//
**********************************************************/

// TODO: add header file guard here

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


// TODO: declare your namespace here

namespace sict {

	// TODO: define the Passenger class here

	class Passenger {
		char pName[32] = { '\0' };
		char dest[32] = { '\0' };

	public:
		Passenger();
		Passenger(const char *name,const char *des);
		bool isEmpty() const;
		void display() const;
	};
}
#endif