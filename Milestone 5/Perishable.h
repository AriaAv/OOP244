// Final Project Milestone 5
//
// Version 1.0
// 2018-08-8
// Aria Avazkhani
//
/////////////////////////////////////////////////////////////////


#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Product.h"
#include "Date.h"
#include <iostream>

using namespace std;
using namespace AMA;

namespace AMA{

	class Perishable : public Product {

		Date exp; //expiry date

	public:
		Perishable(); //default constructor
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;

	};
}
#endif