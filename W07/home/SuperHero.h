/////////////////////////////////////////////////////
// Workshop 7 - Derived Classes
// Date 2018/07/17
// Aria Avazkhani
/////////////////////////////////////////////////////

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		int bon;
		int def;

	public:
		SuperHero();
		SuperHero(const char *, int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero &, const SuperHero &);
}
#endif