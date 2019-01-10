#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double bal, double inte) : Account (bal){

		if (inte > 0)
			interest = inte;
		else
			interest = 0.0;
	}

	void SavingsAccount::monthEnd() {
		 double x = (balance()*interest);
		 credit(x);
	}

	void SavingsAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Savings" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		
		ostr << "Balance: $" << balance() << endl;
		ostr << "Interest Rate (%): " << interest * 100 << endl;
	}

}