#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double inter = 0.05;

	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* type, double bal) {
		iAccount *account = nullptr;
		if (type[0] == 'S') {
			account = new SavingsAccount(bal, inter);
		}
		return account;
	}






}
