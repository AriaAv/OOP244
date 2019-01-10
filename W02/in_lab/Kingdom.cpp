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

	void display(const Kingdom print) {
		cout << print.m_name << ", population "
			<< print.m_population << endl;
	}
}