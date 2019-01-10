// Final Project Milestone 1
//
// Version 1.0
// 2018-07-12
// Aria Avazkhani
//
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>
using namespace std;

namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;

	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;

  class Date {

	  int year;
	  int month;
	  int day;
	  int comp;
	  int error;

      int mdays(int, int)const;
	  void errCode(int);

  public:
	
	  Date();
	  Date(int,int,int);

	  bool operator==(const Date&) const;
	  bool operator!=(const Date&) const;
	  bool operator<(const Date&) const;
	  bool operator>(const Date&) const;
	  bool operator<=(const Date&) const;
	  bool operator>=(const Date&) const;

	  int errCode() const;
	  bool bad() const;
	  void set();

	  std::istream& read(std::istream&);
	  std::ostream& write(std::ostream&) const;
  };
	
std::ostream& operator<<(std::ostream&, const Date&);
std::istream& operator>>(std::istream&, Date&);

}
#endif