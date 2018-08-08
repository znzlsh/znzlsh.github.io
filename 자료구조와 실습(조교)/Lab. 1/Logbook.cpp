// Logbook.cpp: implementation of the Logbook class.
//
//////////////////////////////////////////////////////////////////////

#include "Logbook.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Logbook::Logbook()
{
	setCurrentTime();			 
	initEntry();				 
}

Logbook::~Logbook()
{

}

Logbook::Logbook(int month, int year)
{
	setCurrentTime();		

	logMonth = month;
	logYear = year;

	currentTime->tm_year = year - 1900;
	currentTime->tm_mon = month - 1;

	initEntry();			 
}

void Logbook::putEntry(int day, int value)
{
	entries[day] = value;
}

int Logbook::getEntry(int day) const
{
	return entries[day];
}

int Logbook::getMonth() const
{
	return logMonth;
}

int Logbook::getYear() const
{
	return logYear;
}

int Logbook::getDaysInMonth() const	
{
	return DaysOfMonth[isLeapYear(logYear)][logMonth];
}

int Logbook::isLeapYear(int year) const
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;		// Leap year
	else
		return 0;		// Normal years
}


void Logbook::putEntry(int value)		 
{
	entries[(currentTime->tm_mday - 1)] = value;
}

void Logbook::setCurrentTime()
{	
	// tm structure Used by asctime, gmtime, localtime, mktime, 
	// and strftime to store and retrieve time information.  

	// tm�� ����ü�� �ð� ������ �����ϰ� �ҷ����� ���� asctime, gmtime, localtime, mktime,
	// �׸��� strftime �� ���ؼ� ���˴ϴ�.

	time_t		now;
	time(&now);
	currentTime = localtime(&now);		

	logYear = currentTime->tm_year + 1900;
	logMonth = currentTime->tm_mon + 1;
}

void Logbook::initEntry()
{
	int iDays = getDaysInMonth();
	for (int i = 0; i < iDays; i++)
		entries[i] = 0;
}


void Logbook::displayCalendar() const
{
	int szScreen = 80;

	printf("%35d / %d\n\n", getMonth(), getYear());

	for (int i = 0; i < 7; i++)
	{
		printf("%4c %-6s", ' ', NameOfDay[i]);
	}
	cout << endl;

	int posDay = getDayOfWeek(1);			
	int lastDays = getDaysInMonth();		

	for (int m = 0; m < posDay; m++)		
	{
		printf("%11c", ' ');
	}

	printf("%4c%2d %-3d ", ' ', 1, entries[0]);	

	for (int j = 1; j < lastDays; j++)			
	{
		if ((++posDay) < 7)						
		{
			printf("%4c%2d %-3d ", ' ', j + 1, entries[j]);
		}
		else
		{
			cout << endl;
			posDay = 0;
			printf("%4c%2d %-3d ", ' ', j + 1, entries[j]);
		}
	}
	cout << endl;
}

int Logbook::getDayOfWeek(int day) const
{
	tm		when;
	time_t	result;

	when = *currentTime;
	when.tm_mday = day;

	if ((result = mktime(&when)) != (time_t)-1) //��ȿ�ϸ� W_day ������ ��ȯ
	{
		return when.tm_wday;
	}
	else
	{
		return 0;
	}
}
