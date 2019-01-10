/////////////////////////////////////////////////////
// Workshop 7 - Derived Classes
// Date 2018/07/11
// Aria Avazkhani
/////////////////////////////////////////////////////

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {

	const int max_rounds = 100;

	class Hero {
		char name[41];
		int hp;
		int str;

	public:
		Hero();
		Hero(const char[],const int,const int);
		bool isValid(int);
		bool isEmpty() const;
		void operator-=(int);
		bool isAlive() const;
		std::ostream& pr(std::ostream&) const;
		void fight(int);
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif