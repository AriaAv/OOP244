// TODO: add file header comments here
/**********************************************************
// Workshop 4
// Date 2018-06-10
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
		int year;
		int month;
		int day;

	public:
		Passenger();
		Passenger(const char *name, const char *des);
		Passenger(const char *name, const char *des, const int year,
				  const int month, const int day);
		bool isEmpty() const;
		void display() const;
		const char *name() const;
		bool canTravelWith(const Passenger& pass) const;
	};
}
#endif