// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double b, double f, double m) : Account(b) {
		if (f > 0)
			fee = f;
		else
			fee = 0.0;
		if (m > 0)
			mon = m;
		else
			mon = 0.0;	
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//

	bool ChequingAccount::credit(double a) {
		if (Account::credit(a) == true) {
			Account::debit(fee);
			return true;
		}
		else
			return false;
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

	bool ChequingAccount::debit(double s) {
		if (Account::debit(s) == true) {
			Account::debit(fee);
			return true;
		}
		else
			return false;
	}

	// monthEnd debits month end fee
	//

	void ChequingAccount::monthEnd() {
		debit(mon);
	}

	// display inserts account information into ostream os
	//

	void ChequingAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Chequing" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $" << balance() << endl;
		ostr << "Per Transaction Fee: " << fee << endl;
		ostr << "Monthly Fee: " << mon << endl;
	}


}