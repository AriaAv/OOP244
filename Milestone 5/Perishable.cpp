// Final Project Milestone 5
//
// Version 1.0
// 2018-08-8
// Aria Avazkhani
//
/////////////////////////////////////////////////////////////////


#include "Perishable.h"

namespace AMA {

	Perishable::Perishable() : Product('P') { //default constructor
		v_err.clear();
	}


	std::fstream& Perishable::store(std::fstream& file, bool newLine ) const {	
		/* 
			This function stores a single file record for the current object	
		*/

		Product::store(file, false);
		file << ',' << exp << endl;

		return file;
	}


	std::fstream& Perishable::load(std::fstream& file) {
		/*
			This function extracts the data fields for a 
			single file record from the fstream object
		*/

		Product::load(file);
		exp.read(file);
		file.ignore();

		return file;
	}


	std::ostream& Perishable::write(std::ostream& os, bool linear) const {	
	/*
		This query receives a reference to an ostream object and a bool flag and 
		returns a reference to the modified ostream object. The flag identifies the output format
	*/

		Product::write(os, linear);

		if (isClear() && !isEmpty()){
			if (linear)
				exp.write(os);
			else{
				os << "\n Expiry date: ";
				exp.write(os);
			}
		}
		return os;
	}


	std::istream& Perishable::read(std::istream& is){
		/*
		This function populates the current object with the 
		data extracted from the istream object. 
		*/

		is.clear();
		Product::read(is);
		if (v_err.isClear()){
			cout << " Expiry date (YYYY/MM/DD): ";
			exp.read(is);
		}

		if (exp.errCode() == CIN_FAILED){
			v_err.clear();
			v_err.message("Invalid Date Entry");
		}

		if (exp.errCode() == YEAR_ERROR)
			v_err.message("Invalid Year in Date Entry");

		if (exp.errCode() == MON_ERROR)		{
			v_err.clear();
			v_err.message("Invalid Month in Date Entry");
		}

		if (exp.errCode() == DAY_ERROR){
			v_err.clear();
			v_err.message("Invalid Day in Date Entry");
		}

		if (exp.errCode())
			is.setstate(std::ios::failbit);

		if (exp.errCode() != CIN_FAILED && exp.errCode() != YEAR_ERROR && exp.errCode() != MON_ERROR && exp.errCode() != DAY_ERROR)
			v_err.clear();

		return is;
	}


	const Date& Perishable::expiry() const {
		// This query returns the expiry date for the perishable product

		return exp;

	}

}
