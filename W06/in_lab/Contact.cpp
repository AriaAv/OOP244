// Workshop 6 - Class with a Resource
// Contact.cpp
// Aria Avazkhani
// 2018/07/04

#include <iostream>
#include "Contact.h"
#include <cstring>
#include <string>
using namespace std;
using namespace sict;

namespace sict {

	Contact::Contact() {
		strncpy(name, "\0", sizeof name);
		count = 0;
		phone = nullptr;
	}
	Contact::Contact(const char na[], const long long *p, int num) {

		if (p == nullptr) {
			if (na != nullptr) {
				strncpy(name, na, 20);
				name[19] = '\0';
			}
			else {
				name[0] = '\0';
			}
			count = 0;
			phone = nullptr;
		}
		else {
			count = num;
			strncpy(name, na, 20);
			name[strlen(name)] = '\0';
			phone = new long long[count];
			for (int i = 0; i < count; i++) {
				if (isValid(p[i]) == true) {	
					phone[i] = p[i];
				}
				else {
					name[0] = '\0';
					count = 0;
					phone = nullptr;
				}
			}
		}
	}
	Contact::~Contact() {
		
		delete[] phone;
	}
	bool Contact::isEmpty() const {
			if (name[0]  == '\0')
				return true;
			else
				return false;
	}
	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else if (isEmpty() == false && phone == nullptr) {
			cout << name << endl;
		}
		else {
			cout << name << endl;
			for (int i = 0; i < count; i++) {
				string b = to_string(phone[i]);
				if (b.length() == 11) {
					cout << "(+" << b[0] << ") ";
					for (int x = 1; x < 4; x++) {
						cout << b[x];
					}
					cout << " ";
					for (int y = 4; y < 7; y++) {
						cout << b[y];
					}
					cout << "-";
					for (int j = 7; j < 11; j++) {
						cout << b[j];
					}
					cout << endl;
				}
				else if (b.length() == 12) {
					cout << "(+" << b[0] << b[1] << ") ";
					for (int k = 2; k < 5; k++) {
						cout << b[k];
					}
					cout << " ";
					for (int u = 5; u < 8; u++) {
						cout << b[u];
					}
					cout << "-";
					for (int l = 8; l < 12; l++) {
						cout << b[l];
					}
					cout << endl;
				}
			}
		}

	}
	bool Contact::isValid(const long long p) const {
		if (isEmpty() != false) {
			string a = to_string(p);
			if (a.length() < 11 || a.length() > 12 || a[a.length() - 7] == '0' || a[a.length() - 10] == '0')
				return false;
		}
		return true;
	}

}
