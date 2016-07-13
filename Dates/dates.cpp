#include "dates.h"

Dates::Dates(int day, int month, int year)
{
	wwwd = false;
	workday = false;
	if (correctYear(year))
		this->year = year;
	else
		cout<<"Incorrect year!"<<endl;
	if (correctMonth(month))
		this->month = month;
	else
		cout<<"Incorrect month!"<<endl;
	if (correctDay(day))
		this->day = day;
	else 
		cout<<"Incorrect day!"<<endl;
}

bool Dates::correctDay(const int day)
{
	if (day >= 1 && day <= 31)
	{
		if (month == 2)
		{
			if (isItLeapYear())
			{
				if (day <= 29)
					return true;
				else
					return false;
			}
			else 
			{
				if (day <= 28)
					return true;
				else 
					return false;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30)
				return true;
			else 
				return false;
		}
		else 
		{
			if (day <= 31)
				return true;
			else 
				return false;
		}
	}
	else
		return false;
}

bool Dates::correctMonth(const int month)
{
	if (month >= 1 && month <= 12)
		return true;
	else
		return false;
}

bool Dates::correctYear(const int year)
{
	if (year > 0 && year <= 9999)
		return true;
	else
		return false;
}

int Dates::getDay() const
{
	return day;
}

int Dates::getMonth() const
{
	return month;
}

int Dates::getYear() const
{
	return year;
}

bool Dates::setDay(const int day)
{
	if (correctDay(day))
	{
		this->day = day;
		return true;
	}
	else
		return false;
}

bool Dates::setMonth(const int month)
{
	if (correctMonth(month))
	{
		this->month = month;
		return true;
	}
	else
		return false;
}

bool Dates::setYear(const int year)
{
	if (correctYear(year))
	{
		this->year = year;
		return true;
	}
	else
		return false;
}

bool Dates::isItLeapYear() const
{
	if( (this->getYear() % 400 == 0 || this->getYear() % 100 != 0) && (this->getYear() %4 == 0))
		return true;
	else
		return false;
}

int Dates::calculateDayOfTheWeek() const
{
	//Schwerdtfeger's variation

	//int d = this->getDay();
	//int year = this->getYear();
	//if (this->getMonth() <= 2)
	//	year--;
	//int y = year % 100;
	//int c = year / 100;
	//int m = this->getMonth() - 2;
	//if (m < 1)
	//	m += 12;
	//int w = d + floor(2.6*m - 0.2) + y + floor(y/4) + floor(c/4) - 2*c;
	//cout<<"w = "<<w<<endl;
	//return abs(w) % 7;

	//Zeller’s algorithm

	//int d = this->getDay();
	//int m = this->getMonth();
	//if (m < 3)
	//	m += 12;
	//int year = this->getYear();
	//if (this->getMonth() < 3)
	//	year--;
	//int y = year % 100;
	//int c = year / 100;
	//int w = d + floor((13*(m+1)/5)) + y + floor(y/4) + floor(c/4) + 5*c;
	//return (w % 7);

	//Zeller’s algorithm for computer

	int d = this->getDay();
	int m = this->getMonth();
	if (m < 3)
		m += 12;
	int year = this->getYear();
	if (this->getMonth() < 3)
		year--;
	int w = d + floor((26*(m+1)/10)) + year + floor(year/4) + 6*floor(year/100) + floor(year/400);
	return (w % 7);
}

const char* Dates::getDayOfTheWeek() const
{
	//Schwerdtfeger's variation
	//switch (calculateDayOfTheWeek())
	//{
	//	case 0: return "Sunday";	 
	//	case 1: return "Monday";	 
	//	case 2: return "Tuesday";	 
	//	case 3: return "Wednesday";	 
	//	case 4: return "Thursday";	 
	//	case 5: return "Friday";	 
	//	case 6: return "Saturday";	 
	//}

	//Zeller’s algorithm

	switch (calculateDayOfTheWeek())
	{
		case 0: return "Saturday";	 
		case 1: return "Sunday";	 
		case 2: return "Monday";	 
		case 3: return "Tuesday";	 
		case 4: return "Wednesday";	 
		case 5: return "Thursday";	 
		case 6: return "Friday";	 
	}
}

ostream& operator<<(ostream& out, Dates const& date)
{
	out<<"Choose a preferred date format:"<<endl;
	out<<"1. DD/MM/YYYY"<<endl;
	out<<"2. YYYY/MM/DD"<<endl;
	out<<"3. MM/DD/YYYY"<<endl;
	char choice;
	cin>>choice;
	switch (choice)
	{
		case '1' : out<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear()<<endl; break;
		case '2' : out<<date.getYear()<<"/"<<date.getMonth()<<"/"<<date.getDay()<<endl; break;
		case '3' : out<<date.getMonth()<<"/"<<date.getDay()<<"/"<<date.getYear()<<endl; break;
		default: out<<"No such choice!";
	}
	return out;
}

istream& operator>>(istream& in, Dates& date)
{
	int day, month, year;

	do
	{
		cout<<"Enter year: ";
		in>>year;
		if (!date.setYear(year))
			cout<<"Incorrect year, please enter a new one!"<<endl;
	}
	while (!date.correctYear(year));
	
	do 
	{
		cout<<"Enter month: ";
		in>>month;
		if (!date.setMonth(month))
			cout<<"Incorrect month, please enter a new one!"<<endl;
	}
	while (!date.correctMonth(month));
	
	do
	{
		cout<<"Enter day: ";
		in>>day;
		if (!date.setDay(day))
			cout<<"Incorrect day, please enter a new one!"<<endl;
	}
	while (!date.correctDay(day));

	return in;
}

int Dates::daysInMonth()
{
	if (month == 2)
	{
		if (isItLeapYear())
			return 29;
		else
			return 28;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else 
		return 31;
}

int Dates::daysSoFar() const
{
	Dates tmp = *this;
	int days = 0;
	for (int i = 0; i <	(this->getMonth() - 1); i++)
	{
		days += tmp.daysInMonth();
		tmp.setMonth(tmp.getMonth() - 1);
	}
	days += this->getDay();
	return days;
}

Dates Dates::operator+(int days) const
{
	Dates tmp = *this;
	if (this->wwwd)
	{
		for (int i = 0; i < days; i++)
		{
			tmp.addOne();
			while (!tmp.isItWorkDay())
				tmp.addOne();
		}
		return tmp;
	}
	while (days >= 365 + tmp.isItLeapYear())
	{
		days -= 365 + tmp.isItLeapYear();
		tmp.setYear(tmp.getYear() + 1);
	}
	if (days + tmp.daysSoFar() > 365 + tmp.isItLeapYear())
		tmp.setYear(tmp.getYear() + 1);
	while ((tmp.getDay() + days) > tmp.daysInMonth())
	{
		days -= tmp.daysInMonth();
		if (tmp.getMonth() < 12)
			tmp.setMonth(tmp.getMonth() + 1);
		else 
			tmp.setMonth(1);
	}
	tmp.setDay(tmp.getDay() + days);

	if (this->workday)
	{
		tmp = tmp.closestWorkDay();
	}
	return tmp;
}

Dates& Dates::operator+=(const int days)
{
	*this = *this + days;
	return *this;
}

Dates& Dates::operator++()
{
	*this += 1;
	return *this;
}

Dates Dates::operator++(int hax)
{
	Dates tmp = *this;
	++(*this);
	return tmp;
}

Dates Dates::operator-(int days) const
{
	Dates tmp = *this;
	if (this->wwwd)
	{
		for (int i = 0; i < days; i++)
		{
			tmp.substractOne();
			while (!tmp.isItWorkDay())
				tmp.substractOne();
		}
		return tmp;
	}
	while (days >= 365 + tmp.isItLeapYear())
	{
		days -= 365 + tmp.isItLeapYear();
		tmp.setYear(tmp.getYear() - 1);
	}
	if ((tmp.daysSoFar() - days) < 1)
		tmp.setYear(tmp.getYear() - 1);
	while ((tmp.getDay() - days) < 1)
	{
		days -= tmp.getDay();
		if (tmp.getMonth() != 1)
			tmp.setMonth(tmp.getMonth() - 1);
		else
			tmp.setMonth(12);
		tmp.setDay(tmp.daysInMonth());
	}
	if (!tmp.setDay(tmp.getDay() - days))
	{
		tmp.setMonth(tmp.getMonth() +1);
		tmp.setDay(1);
	}
	if (this->workday)
	{
		tmp = tmp.closestWorkDay();
	}
	return tmp;
}

Dates& Dates::operator-=(int days)
{
	*this = *this - days;
	return *this;
}

Dates& Dates::operator--()
{
	*this -= 1;
	return *this;
}

Dates Dates::operator--(int hax)
{
	Dates tmp = *this;
	*this -= 1;
	return tmp;
}

int Dates::daysInNextMonth() const
{
	Dates tmp = *this;
	if (++tmp.month <= 12)
		return tmp.daysInMonth();
	else
	{
		tmp.year++;
		tmp.month -= 12;
		return tmp.daysInMonth();
	}
}

Dates Dates::operator*(const int months)
{
	int days = 0;
	Dates tmp = *this;
	for (int i = 0; i < months; i++)
	{
		days += tmp.daysInMonth();
		if (tmp.daysInMonth() > tmp.daysInNextMonth() && tmp.getDay() > tmp.daysInNextMonth())
			days -= (tmp.daysInMonth() - tmp.daysInNextMonth());
	}
	tmp += days;
	return tmp;
}

Dates& Dates::operator*=(const int months)
{
	*this = *this * months;
	return *this;
}

int Dates::daysInPreviousMonth() const
{
	Dates tmp = *this;
	if (--tmp.month >= 1)
		return tmp.daysInMonth();
	else
	{
		tmp.year--;
		tmp.month = 12;
		return tmp.daysInMonth();
	}
}

Dates Dates::operator/(const int months)
{
	Dates tmp = *this;
	int days = 0;
	for (int i = 0; i < months; i++)
	{
		days -= tmp.daysInPreviousMonth();
		if (tmp.daysInMonth() > tmp.daysInPreviousMonth() && tmp.getDay() > tmp.daysInPreviousMonth())
			days -= (tmp.daysInMonth() - tmp.daysInPreviousMonth());
	}
	tmp -= abs(days);
	return tmp;
}

Dates& Dates::operator/=(const int months)
{
	*this = *this / months;
	return *this;
}

Dates Dates::operator&(const int years)
{
	Dates tmp = *this;
	int days = 0;
	for (int i = 0; i < years; i++)
	{
		days += 365 + tmp.isItLeapYear();
	}
	tmp += days;
	return tmp;
}

Dates& Dates::operator&=(const int years)
{
	*this = *this & years;
	return *this;
}

Dates Dates::operator|(const int years)
{
	Dates tmp = *this;
	int days = 0;
	for (int i = 0; i < years; i++)
		days += 365 + tmp.isItLeapYear();
	tmp -= days;
	return tmp;
}

Dates& Dates::operator|=(const int years)
{
	*this = *this | years;
	return *this;
}

Dates Dates::operator^(const int weeks)
{
	Dates tmp = *this;
	int days = 0;
	for (int i = 0; i < weeks; i++)
		days += 7;
	tmp += days;
	return tmp;
}

Dates& Dates::operator^=(const int weeks)
{
	*this = *this ^ weeks;
	return *this;
}

Dates Dates::operator%(const int weeks)
{
	Dates tmp = *this;
	int days = 0;
	for (int i = 0; i < weeks; i++)
		days += 7;
	tmp -= days;
	return tmp;
}

Dates& Dates::operator%=(const int weeks)
{
	*this = *this % weeks;
	return *this;
}

int yd(Dates first, Dates second)
{
	int days = 0;
	while (first.getYear() - second.getYear() > 1)
	{
		first.setYear(first.getYear() - 1);
		days += 365 + first.isItLeapYear();
	} 
	return days;
}

int md(Dates first, Dates second)
{
	int days = 0;
	if (first.getYear() != second.getYear())
	{
		int n = first.getMonth() - 1;
		for (int i = 0; i < n; i++)
		{
			first.setMonth(first.getMonth() - 1);
			days += first.daysInMonth();
		}
		n = 12 - second.getMonth();
		for (int i = 0; i < n; i++)
		{
			second.setMonth(second.getMonth() + 1);
			days += second.daysInMonth();
		}
		return days;
	}
	else
	{
		int n = first.getMonth() - second.getMonth() - 1;
		for (int i = 0; i < n; i++)
		{
			second.setMonth(second.getMonth() + 1);
			days += second.daysInMonth();
		}
		return days;
	}
}

int dd(Dates first, Dates second)
{
	int days = 0;
	days += first.getDay();
	days += second.daysInMonth() - second.getDay();
	return days;
}

int Dates::operator-(Dates const& date) const
{
	Dates tmp1 = *this;
	Dates tmp2 = date;
	int days = 0;
	if (tmp1.getYear() == tmp2.getYear())
	{
		if (tmp1.getMonth() == tmp2.getMonth())
			return abs(tmp1.getDay() - tmp2.getDay());
		else
		{
			if (tmp1.getMonth() > tmp2.getMonth())
			{
				days += md(tmp1, tmp2);
				days += dd(tmp1, tmp2);
			}
			else
			{
				days += md(tmp2,tmp1);
				days += dd(tmp2,tmp1);
			}
			return days;
		}
	}
	if (tmp1.getYear() > tmp2.getYear())
	{
		days += yd(tmp1, tmp2);
		days += md(tmp1, tmp2);
		days += dd(tmp1, tmp2);
	}
	else
	{
		days += yd(tmp2, tmp1);
		days += md(tmp2, tmp1);
		days += dd(tmp2, tmp1);
	}
	return days;
}

int Dates::operator/(Dates const& date) const
{
	if (this->getYear() == date.getYear()) 
		return abs(this->getMonth() - date.getMonth());
	else
		return abs(this->getYear() - date.getYear()) * 12 + abs(this->getMonth() - date.getMonth());
}

int Dates::operator|(Dates const& date) const
{
	return abs(this->getYear() - date.getYear());
}

Dates addUp(Dates& date)
{
	int days = 13;
	if (date.getDay() + days > date.daysInMonth())
	{
		days += date.getDay() - date.daysInMonth();
		date.setMonth(date.getMonth() + 1);
		Dates easterDate(days, date.getMonth(), date.getYear());
		return easterDate;
	}
	else
	{
		Dates easterDate(date.getDay() + days, date.getMonth(), date.getYear());
		return easterDate;
	}
}

Dates Dates::easter() const
{
	Dates easter;
	int a, b, c, d, e;
	a = this->getYear() % 19;
	b = this->getYear() % 4;
	c = this->getYear() % 7;
	d = (19 * a + 15) % 30;
	e = (2 * b + 4 * c + 6 * d + 6) % 7;
	if(d + e >= 10)
	{
		Dates tmp(d + e - 9,4,this->getYear());
		easter = addUp(tmp);
	}
	else
	{
		Dates tmp(22 + d + e,3,this->getYear());
		easter = addUp(tmp);
	}
	return easter;
}

bool holiday(Dates const& date)
{
	Dates easter = date.easter();
	Dates fridayBeforeEaster = easter - 2;
	Dates easterMonday = ++easter;
	Dates* holiday[13];
	holiday[0] = &Dates(1,1);
	holiday[1] = &Dates(3,3);
	holiday[2] = &fridayBeforeEaster;
	holiday[3] = &easterMonday;
	holiday[4] = &Dates(1,5);
	holiday[5] = &Dates(6,5);
	holiday[6] = &Dates(24,5);
	holiday[7] = &Dates(6,9);
	holiday[8] = &Dates(22,9);
	holiday[9] = &Dates(1,11);
	holiday[10] = &Dates(24,12);
	holiday[11] = &Dates(25,12);
	holiday[12] = &Dates(26,12);
	for (int i = 0; i < 13; i++)
	{
		if (date.getMonth() == holiday[i]->getMonth() && date.getDay() == holiday[i]->getDay())
			return true;
	}
	return false;
}

bool Dates::isItWorkDay() const
{
	if (strcmp(this->getDayOfTheWeek(), "Saturday") == 0 || strcmp(this->getDayOfTheWeek(), "Sunday") == 0)
		return false;
	if (holiday(*this))
		return false;
	return true;
}

void Dates::addOne()
{
	int days = 1;
	if (days + this->daysSoFar() > 365 + this->isItLeapYear())
		this->setYear(this->getYear() + 1);
	if ((this->getDay() + days) > this->daysInMonth())
	{
		if (this->getMonth() < 12)
			this->setMonth(this->getMonth() + 1);
		else 
			this->setMonth(1);
		this->setDay(1);
	}
	else
		this->setDay(this->getDay() + days);
}

void Dates::substractOne()
{
	int days = 1;
	if ((this->daysSoFar() - days) < 1)
		this->setYear(this->getYear() - 1);
	if ((this->getDay() - days) < 1)
	{
		if (this->getMonth() != 1)
			this->setMonth(this->getMonth() - 1);
		else
			this->setMonth(12);
		this->setDay(this->daysInMonth());
	}
	if (!this->setDay(this->getDay() - days))
	{
		this->setMonth(this->getMonth() +1);
		this->setDay(1);
	}
}

Dates Dates::closestWorkDay(const char sign)
{
	Dates tmpB = *this;
	Dates tmpF = *this;
	int bCounter = 0, fCounter = 0;
	while(!tmpB.isItWorkDay())
	{
		tmpB.substractOne();
		bCounter++;
	}
	while(!tmpF.isItWorkDay())
	{
		tmpF.addOne();
		fCounter++;
	}
	if (sign == '0')
	{
		if (fCounter > bCounter)
			return tmpB;
		else
			return tmpF;
	}
	if (sign == '<' || sign == '-')
		return tmpB;
	if (sign == '>' || sign == '+')
		return tmpF;
	return *this;
}

void Dates::workWithWorkDays(bool change)
{
	this->wwwd = change;
}

void Dates::changeToWorkDay(bool change)
{
	this->workday = change;
}