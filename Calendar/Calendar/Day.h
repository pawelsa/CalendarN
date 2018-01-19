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


	Day(int dayNumber): NameOfDay(dim::DayNames.at(dayNumber)), DayNumber(dayNumber)
	{/*
		this->NameOfDay = dim::DayNames.at(dayNumber);
		this->DayNumber = dayNumber;*/
	};


	~Day() { }


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

private:


	std::list<Event> EventList;

	const std::string NameOfDay;
	const int DayNumber;
};