#pragma once
#include "Event.h"
#include <string>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class Day
{
public:



	Day() {};
	Day(int dayNumber)
	{
		this->NameOfDay = DayNames.at(dayNumber);
		this->DayNumber = dayNumber;
	};


	~Day() { }

	std::list<Event> EventList;

	std::string NameOfDay;
	int DayNumber;

	std::vector<std::string> DayNames = { "Monday", "Tjuzdej", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	void AddEvent(Event eventToAdd)
	{
		try
		{
			EventList.push_back(eventToAdd);
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning adding event" << ex.what() << std::endl;
		}
	};

	void RemoveEvent(Event eventToRemove)
	{
		auto tempList = this->EventList;
		try
		{
			tempList.remove(eventToRemove);
			this->EventList = tempList;
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning removing event" << ex.what() << std::endl;
		}
	}
};