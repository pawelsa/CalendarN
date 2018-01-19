#pragma once
#include <string>
class Day
{
public:

	Day();
	Day(std::string name, int dayNumber)
	{
		this->NameOfDay = name;
		this->DayNumber = dayNumber;
	};


	~Day()
	{

	}

	std::string NameOfDay;
	int DayNumber;

	
};