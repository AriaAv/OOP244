/////////////////////////////////////////////////////
// Workshop 7 - Derived Classes
// Date 2018/07/17
// Aria Avazkhani
/////////////////////////////////////////////////////


#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
#include <cstring>


using namespace std;
using namespace sict;

namespace sict {

	SuperHero::SuperHero() : Hero(){
		bon = 0;
		def = 0;
	}
	SuperHero::SuperHero(const char *n, int hp, int att, int bns, int dfn) : Hero(n,hp,att){
		if (hp != 0 || n[0] != '\0') {
			bon = bns;
			def = dfn;
		}
		else
			SuperHero();
	}
	int SuperHero::attackStrength() const {
		if (bon != 0) {
			return Hero::attackStrength() + bon;
		}
		else
			return 0;
	}
	int SuperHero::defend() const {
		if (def != 0) {
			return def;
		}
		else
			return 0;
	}
	const SuperHero& operator*(const SuperHero &first, const SuperHero &second) {

		cout << "Super Fight! " << first << " vs " << second << " : ";
		SuperHero one = first;
		SuperHero two = second;
		const SuperHero *w = nullptr;
		int r = 0;

		for (r = 1; r < max_rounds; r++) {
			one.fight(two.attackStrength() - one.defend());
			two.fight(one.attackStrength() - two.defend());
			if (one.isAlive() == false || two.isAlive() == false) {
				break;
			}
		}
		if (one.isAlive() == false && two.isAlive() == false)
			w = &first;
		else if (one.isAlive() == true)
			w = &first;
		else
			w = &second;
		cout << "Winner is " << *w << " in " << r << " rounds." << endl;

		return *w;
	}
}