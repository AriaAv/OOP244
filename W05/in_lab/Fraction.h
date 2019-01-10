/**********************************************************
// Workshop 5
// Date 2018-06-13
// Author Aria Avazkhani
//
**********************************************************/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int dom;
		int num;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int a, int b);
		bool isEmoty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;

	};
}
#endif
