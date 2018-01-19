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


	Day(int dayNumber): NameOfDay(dim::DayNames.at(dayNumber)), DayNumber(dayNumber) { 
		Event eventToAdd = Event(12, 13, "test", Person("ee", "bb"));
		AddEvent(eventToAdd);
	
	
	
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
			//std::vector<int> vec;
			//// .. put in some values ..
			//int int_to_remove = n;
			//vec.erase(std::remove(vec.begin(), vec.end(), int_to_remove), vec.end());

			tempList.erase(std::remove(tempList.begin(), tempList.end(), eventToRemove), tempList.end());
			this->EventList = tempList;
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning removing event" << ex.what() << std::endl;
		}
	}

	bool HaveAnyEvent()
	{
		if (EventList.size() == 0)
			return false;
		else
			return true;
	};

private:


	std::vector<Event> EventList;

	const std::string NameOfDay;
	const int DayNumber;
};