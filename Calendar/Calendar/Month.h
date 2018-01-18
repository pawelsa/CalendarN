#pragma once
#include "Day.h"
#include <list>
#include <string.h>


class Month
{
public:
	Month() {};
	Month(std::string nameOfMonth)
	{
		this->Name = nameOfMonth;
	};

	Month(std::string nameOfMonth, int monthNumber, int year, int firstDay)
	{
		this->Name = nameOfMonth;
		this->Number = monthNumber;
		this->NumberOfDaysInMonth = NumberOfDays(monthNumber, year);
		int Counter = firstDay;
		for (int i = 0; i < NumberOfDaysInMonth; i++)
		{
			Day* dayToAdd = new Day(Counter);
			Counter++;
			if (Counter == 7)
			{
				Counter = 0;
			}
			Days.push_back(dayToAdd);

		}
	};

	~Month();

	std::list<Day*> Days;
	std::string Name;
	int NumberOfDaysInMonth;
	int Number;


	int NumberOfDays(int monthNumber, int year)
	{
		// January
		if (monthNumber == 0)
			return (31);

		// February
		if (monthNumber == 1)
		{
			// If the year is leap then February has
			// 29 days
			if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
				return (29);
			else
				return (28);
		}

		// March
		if (monthNumber == 2)
			return (31);

		// April
		if (monthNumber == 3)
			return (30);

		// May
		if (monthNumber == 4)
			return (31);

		// June
		if (monthNumber == 5)
			return (30);

		// July
		if (monthNumber == 6)
			return (31);

		// August
		if (monthNumber == 7)
			return (31);

		// September
		if (monthNumber == 8)
			return (30);

		// October
		if (monthNumber == 9)
			return (31);

		// November
		if (monthNumber == 10)
			return (30);

		// December
		if (monthNumber == 11)
			return (31);
	}
};