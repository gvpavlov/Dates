#include "dates.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	Dates a(17,4,2014);
	cout<<a<<endl;
	cout<<a.getDayOfTheWeek()<<endl;
	Dates b(1,1,2014);
	cout<<b.getDayOfTheWeek()<<endl;
	Dates c(31,12,2000);
	cout<<c.getDayOfTheWeek()<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	Dates d;
	cin>>d;
	cout<<d<<endl;
	Dates e = a + 29;
	cout<<e<<endl;
	a += 29;
	cout<<a<<endl;
	cout<<++e<<endl;
	cout<<e++<<endl;
	cout<<e<<endl;

	Dates f = a - 365;
	cout<<f<<endl;

	cout<<--a<<endl;
	b = a--;
	cout<<b<<endl;
	cout<<a<<endl;
	
	Dates h = a * 1;
	cout<<h<<endl;
	h *= 1;
	cout<<h<<endl;

	Dates i = a / 1;
	cout<<i<<endl;
	i /= 1;
	cout<<i<<endl;

	Dates z = a & 1;
	cout<<z<<endl;
	z &= 1;
	cout<<z<<endl;

	Dates u = a | 1;
	cout<<u<<endl;
	u |= 1;
	cout<<u<<endl;

	cout<<a.getDayOfTheWeek()<<endl;
	Dates t = a ^ 1;
	cout<<t<<endl;
	cout<<t.getDayOfTheWeek()<<endl;
	t ^= 1;
	cout<<t<<endl;
	cout<<t.getDayOfTheWeek()<<endl;

	cout<<a.getDayOfTheWeek()<<endl;
	Dates q = a % 1;
	cout<<q<<endl;
	cout<<q.getDayOfTheWeek()<<endl;
	q %= 1;
	cout<<q<<endl;
	cout<<q.getDayOfTheWeek()<<endl;

	cout<<a-b<<endl;
	cout<<b-a<<endl;

	cout<<a/b<<endl;
	cout<<b/a<<endl;
	
	cout<<(b|a)<<endl;
	cout<<(a|b)<<endl;
	
	cout<<a.getDayOfTheWeek()<<endl;
	cout<<a.isItWorkDay()<<endl;

	Dates l = a.closestWorkDay();
	cout<<l<<endl;

	a.changeToWorkDay(true);
	a = a + 1;
	cout << a;
	a.changeToWorkDay(false);
	a += 3;
	cout << a;

	Dates m(17,4,2014);
	m.workWithWorkDays(true);
	m += 4;
	cout<<m<<endl;
	m -= 4;
	cout<<m<<endl;
	m.workWithWorkDays(false);
	m += 4;
	cout<<m<<endl;

	return 0;
}