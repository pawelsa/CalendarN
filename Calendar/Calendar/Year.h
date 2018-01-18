#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Dimensions.h"
#include "Month.h"
#include <list>
extern sf::RenderWindow window;

class Year {





public:

	Year(int mYear) :YearNumber(mYear) {


		for (int i = 0; i < 12; i++)
		{
			auto current = DayNumber(1, i, mYear);

			Month* monthToAdd = new Month(MonthNames.at(i), i, mYear, current);
			Months.push_back(monthToAdd);

		}


	}



	int returnYear() {

		return YearNumber;
	}

private:

	sf::Text year_number;				//Number in square

	const int YearNumber;

	std::list<Month*> Months;


	int DayNumber(int day, int month, int year)
	{

		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
			4, 6, 2, 4 };
		year -= month < 3;
		return (year + year / 4 - year / 100 +
			year / 400 + t[month-1] + day) % 7;
	}

	std::vector<std::string> MonthNames = { "January", "February", "March", "April", "May", "June", "July", "August" , "September" , "October" , "November" , "December" };
};
