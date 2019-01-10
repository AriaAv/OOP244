/**********************************************************
// Workshop 5
// Date 2018-06-13
// Author Aria Avazkhani
//
**********************************************************/

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;
using namespace sict;
// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		dom = 0;
		num = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int a, int b) {
		if (a < 0 || b < 1) {
			//Fraction();
			dom = 0;
			num = 0;
		}
		else {
			num = a;
			dom = b;
			reduce();//
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		if (num > dom)
			return num;
		else
			return dom;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		if (num < dom)
			return num;
		else
			return dom;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce(){
		int a = gcd();
		num = num / a;
		dom = dom / a;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmoty())
			cout << "no fraction stored";
		else {
			if (dom == 1)
				cout << num;
			else
				cout << num << "/" << dom;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmoty() const {
		if (dom == 0 || num == 0)
			return true;
		else
			return false;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction f;
		if (!(rhs.isEmoty() || isEmoty())) {
			f.num = dom * rhs.num + num * rhs.dom;
			f.dom = dom * rhs.dom;
		}
		return f; 
		
	}
}