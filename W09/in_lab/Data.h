/////////////////////////////////////////////////////////////////
// Workshop 9
//
// Version 1.0
// 2018-07-25
// Aria Avazkhani
// 134465160
//
/////////////////////////////////////////////////////////////////


#ifndef SICT_DATA_H
#define SICT_DATA_H

#include <iostream>
#include <cstring>
using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	//
	template <typename T>
	T max(const T* data, int n) {
		T mx = data[0];
		for (int i = 1; i < n; i++) {
			if (mx < data[i])
				mx = data[i];
		}
		return mx;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T* data, int n) {
		T mn = data[0];
		for (int i = 1; i < n; i++) {
			if (mn > data[i])
				mn = data[i];
		}
		return mn;
	}
        
	// sum returns the sum of n items in data
	//    
	template <typename T>
	T sum(const T* data, int n) {
		T sm = 0;
		for (int i = 0; i < n; i++) {
			sm += data[i];
		}
		return sm;
	}
	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T* data, int n) {
		double avg = sum(data, n) / n;
		return avg;
	}
	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore();
			input >> data[i];
			if (input.fail())
				return false;
		}
		return true;
	}
	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << right << name;
		for (int i = 0; i < n; i++) {
			cout.width(15);
			cout << data[i];
		}
		cout << endl;
	}

	template<typename T>
	T readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();
		if (ok) {
			input.get(rowname, 2000, ',');
			if (std::strcmp(rowname, name) != 0) {
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}
		if (ok)
			ok = read(input, data, n);
			input.ignore(2000, '\n');
			return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif

