/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2018-05-23
// Author Aria Avazkhani
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 

	void display(const Kingdom *print) {
		cout << print->m_name << ", population "
			<< print->m_population << endl;
	}
	void display(const Kingdom *p, int a) {
		int total = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < a; i++) {
			total = total + p[i].m_population;
			cout << i+1 << ". ";
			display(&p[i]);
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}
}