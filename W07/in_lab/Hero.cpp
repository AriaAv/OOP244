/////////////////////////////////////////////////////
// Workshop 7 - Derived Classes
// Date 2018/07/11
// Aria Avazkhani
/////////////////////////////////////////////////////


#include <iostream>
#include "Hero.h"
#include <cstring>


using namespace std;
using namespace sict;

namespace sict {

	Hero::Hero() {
		name[0] = '\0';
		hp = 0;
		str = 0;
	}
	Hero::Hero(const char n[],const int h,const int s) {
		if (isValid(h) == true && isValid(s) == true && (n != nullptr || n[0] != '\0')) {
			strncpy(name, n, strlen(n));
			name[strlen(n)] = '\0';
			hp = h;
			str = s;
		}
		else
			Hero();
	}
	bool Hero::isValid(int a) {
		if (a > 0)
			return true;
		else
			return false;
	}
	bool Hero::isEmpty() const{
		if ((name[0] == '\0' || name == nullptr) && str == 0 && hp == 0)
			return true;
		else
			return false;
	}
	void Hero::operator-=(int attack) {
		if (isValid(attack) == true) {
			hp = hp - attack;
			if (hp < 0)
				hp = 0;
		}
	}
	bool Hero::isAlive() const {
		if (hp > 0)
			return true;
		else
			return false;
	}
	int Hero::attackStrength() const {
		return str;
	}
	ostream& operator<<(ostream& os, const Hero& hero) {
		return hero.pr(os);
	}
	ostream& Hero::pr(ostream& os) const{
		if (!isEmpty() == true)
			os << name;
		else
			cout << "No hero";
		return os;
	}
	void Hero::fight(int a) {
		hp -= a;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {

		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		Hero one = first;
		Hero two = second;
		const Hero *w = nullptr;
		int r = 0;

		for (r= 1; r < max_rounds; r++) {
			one.fight(two.attackStrength());
			two.fight(one.attackStrength());
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