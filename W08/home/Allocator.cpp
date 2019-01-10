#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
	const double inter = 0.05;
	const double trans = 0.50;
	const double monthly = 2.00;

	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* type, double bal) {
		iAccount *account = nullptr;
		if (type[0] == 'S') {
			account = new SavingsAccount(bal, inter);
		}
		if (type[0] == 'C') {
			account = new ChequingAccount(bal, trans, monthly);
		}
		return account;
	}






}
