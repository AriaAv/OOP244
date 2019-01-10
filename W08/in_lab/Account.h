
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>
#include "iAccount.h"
using namespace std;

namespace sict {
   
	class Account : public iAccount {

		double bala;

	protected:

		double balance() const;
	public:
		// TODO: constructor initializes account balance, defaults to 0.0 

		Account(double);
		// TODO: credit adds +ve amount to the balance 

		bool credit(double);
		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};

	iAccount* CreateAccount(const char*, double);
}
#endif
