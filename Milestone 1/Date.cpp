// Final Project Milestone 1
//
// Version 1.0
// 2018-07-12
// Aria Avazkhani
//
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
  void Date::errCode(int errorCode) {
	  error = errorCode;
  }

  void Date::set() {
	  day = 0;
	  month = 0;
	  year = 0;
	  comp = 0;
  }

  Date::Date() {
	  set();
	  errCode(NO_ERROR);
  }
  /*
  Date::Date(int y, int m, int d) {
	  if (y <= max_year && y >= min_year) {
		  if (m <= 12 && m >= 1) {
			  if (d <= 31 && d >= 1 && day <= mdays(m,y)) {
				  year = y;
				  month = m;
				  day = d;
				  errCode(NO_ERROR);
				  comp = year * 372 + month * 13 + day;
			  }
			  else {
				  set();
				  errCode(DAY_ERROR);
			  }
		  }
		  else {
			  set();
			  errCode(MON_ERROR);
		  }
	  }
	  else {
		  set();
		  errCode(YEAR_ERROR);
	  }
  }
  */
  ////////////////////////////
  Date::Date(int y, int m, int d) {

	  if (year < y || y > max_year) {
		  errCode(YEAR_ERROR);
	  }
	  else if (m < 1 || m> 12) {
		  errCode(MON_ERROR);
	  }
	  else if (d < 1 || d > mdays(m, y)) {
		  errCode(DAY_ERROR);
	  }

	  if (((y > min_year && y < max_year) && (m > 1 && m < 12) && (d > 1 && d < mdays(m, y)))) {
		  year = y;
		  month = m;
		  day = d;
		  comp = year * 272 + month * 13 + day;
		  errCode(NO_ERROR);
	  }
	  else {

		  *this = Date();
		  comp = 0;
	  }
  }

  ////////////////////////////////////
  bool Date::operator==(const Date& rhs) const {
	  if (year != 0 && rhs.year != 0)
		  return comp == rhs.comp;
	  else
		  return false;
  }
  bool Date::operator!=(const Date& rhs) const {
	  if (year != 0 && rhs.year != 0)
		  return comp != rhs.comp;
	  else
		  return false;
  }
  bool Date::operator<(const Date& rhs) const {
	  if (year != 0 && rhs.year != 0)
		  return comp < rhs.comp;
	  else
		  return false;
  }
  bool Date::operator>(const Date& rhs) const {
	  if (year != 0 && rhs.year != 0)
		  return comp > rhs.comp;
	  else
		  return false;
  }
  bool Date::operator<=(const Date& rhs) const {
	  if (year != 0 && rhs.year != 0)
		  return comp <= rhs.comp;
	  else
		  return false;
  }
  bool Date::operator>=(const Date& rhs) const {
	  if (year != 0 && rhs.year != 0)
		  return comp >= rhs.comp;
	  else
		  return false;
  }

  int Date::errCode() const {
	  return error;
  }
  bool Date::bad() const {
	  return error != NO_ERROR;
  }

  /*
  std::istream& Date::read(std::istream& istr) {

	  char e;
	  istr >> year >> e >> month >> e >> day;
	  if (istr.fail())
	  {
		  errCode(CIN_FAILED);
	  }
	  else {
		  if (year < min_year || year > max_year)
			  errCode(YEAR_ERROR);
		  else if (month < 1 || month > 12)
			  errCode(MON_ERROR);
		  else if (day < 1 || day > mdays(month, year))
			  errCode(DAY_ERROR);
	  }
	  return istr;
  }
  */
  ///////////////////////
  std::istream& Date::read(std::istream& istr) {
	  int y, m, d;
	  char c;
	  istr >> y >> c;
	  istr >> m >> c;
	  istr >> d;
	  if (istr.fail()) {
		  errCode(CIN_FAILED);
		  return istr;
	  }

	  else if (y < min_year || y > max_year) {
		  errCode(YEAR_ERROR);
	  }
	  else if (m < 1 || m> 12) {
		  errCode(MON_ERROR);
	  }
	  else if (d < 1 || d > mdays(m, y)) {
		  errCode(DAY_ERROR);
	  }
	  else {
		  year = y;
		  month = m;
		  day = d;
	  }
	  return istr;
  }

  //////////////////////
  std::ostream& Date::write(std::ostream& ostr) const {
	  ostr << year << '/';
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << month << '/';
	  ostr.width(2);
	  ostr << day;
	  return ostr;
  }
  
  std::ostream& operator<<(std::ostream& ostr, const Date& date) {
	  return date.write(ostr);
  }
  std::istream& operator>>(std::istream& istr, Date& date) {
	  return date.read(istr);
  }
}
