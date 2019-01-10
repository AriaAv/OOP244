// Workshop 6 - Class with a Resource
// Contact.h
// Aria Avazkhani
// 2018/07/04
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact {
		char name[20];
		long long *phone;
		int count;
		bool isValid(const long long) const;
	public:
		Contact();
		Contact(const char [], const long long *, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
#endif