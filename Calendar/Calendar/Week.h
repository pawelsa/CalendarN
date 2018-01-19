#pragma once
#include <list>
#include "Day.h"
#include <vector>

class Week
{
public:

	Week() {};
	Week(int numberOfWeek)
	{
		this->WeekNumber = numberOfWeek;
		Init();
	};

	~Week()
	{
			
	}

	void Init()
	{
		for (int i = 0; i < 7; i++)
		{
			Day* dayToAdd = new Day(DayNames.at(i), i);
			DaysInWeek.push_front(dayToAdd);
		}
	}

	std::list<Day*> DaysInWeek;
	int WeekNumber;


private:
	std::vector<std::string> DayNames = {"Monday", "Teusday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

};