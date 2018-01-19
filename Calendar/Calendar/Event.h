#pragma once
#include <iostream>
#include "Person.h"
class Event {
	int StartingTime, EndingTime;
	std::string Description;
	Person Man;
public:
	Event()
	{

	}
	Event(int startingtime, int endingtime, std::string description, Person man)
	{
		this->StartingTime = startingtime;
		this->EndingTime = endingtime;
		this->Description = description;
		this->Man = man;
	}
	~Event()
	{

	}

};