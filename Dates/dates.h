#ifndef DATES_H_
#define DATES_H_

#include <iostream>
using namespace std;

class Dates
{
private:
	int day;
	int month;
	int year;
	bool workday;
	bool wwwd;
	bool correctDay(const int);
	bool correctMonth(const int);
	bool correctYear(const int);
	int calculateDayOfTheWeek() const;
	bool isItLeapYear() const;
	int daysInMonth();
	int daysSoFar() const;
	int daysInNextMonth() const;
	int daysInPreviousMonth() const;
	friend int yd(Dates, Dates);
	friend int md(Dates, Dates);
	friend int dd(Dates, Dates);
	friend bool holiday(Dates const&);
	Dates easter() const;
	friend Dates addUp(Dates&);
	void addOne();
	void substractOne();
public:
	Dates(int = 1, int = 1, int = 1);
	int getDay() const;
	bool setDay(const int);
	int getMonth() const;
	bool setMonth(const int);
	int getYear() const;
	bool setYear(const int);
	const char* getDayOfTheWeek() const;
	friend ostream& operator<<(ostream&, Dates const&);
	friend istream& operator>>(istream&, Dates&);
	Dates operator+(int) const;
	Dates& operator+=(const int);
	Dates& operator++();
	Dates operator++(int);
	Dates operator-(int) const;
	Dates& operator-=(const int);
	Dates& operator--();
	Dates operator--(int);
	Dates operator*(const int);
	Dates& operator*=(const int);
	Dates operator/(const int);
	Dates& operator/=(const int);
	Dates operator&(const int);
	Dates& operator&=(const int);
	Dates operator|(const int);
	Dates& operator|=(const int);
	Dates operator^(const int);
	Dates& operator^=(const int);
	Dates operator%(const int);
	Dates& operator%=(const int);
	int operator-(Dates const&) const;
	int operator/(Dates const&) const;
	int operator|(Dates const&) const;
	bool isItWorkDay() const; 
	Dates closestWorkDay(const char = '0');
	void workWithWorkDays(bool);
	void changeToWorkDay(bool);
};

#endif