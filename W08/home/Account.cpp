#include <iostream>
#include "Account.h"

namespace sict {

	Account::Account(double bal) {
		if (bal > 0)
			bala = bal;
		else
			bala = 0;
	}

	bool Account::credit(double add) {
		if (add > 0){
			bala += add;
			return true;
		}
		else
			return false;
	}

	bool Account::debit(double sub) {
		if (sub > 0) {
			bala -= sub;
			return true;
		}
		else
			return false;
	}

	double Account::balance() const {
		return bala;
	}

}