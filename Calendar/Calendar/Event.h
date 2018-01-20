#pragma once
#include <iostream>
#include "Person.h"
class Event {

	int StartingTime, EndingTime;
	std::string Description;
	Person Man;

public:

	Event(int startingtime, int endingtime, std::string description, Person man)
	{
		this->StartingTime = startingtime;
		this->EndingTime = endingtime;
		this->Description = description;
		this->Man = man;
	}

	~Event() {};

	bool operator ==(const Event& other) const
	{
		if (this->Description == other.Description && this->StartingTime == other.StartingTime && this->EndingTime == other.EndingTime && this->Man == other.Man)
			return true;

		return false;
	}


	std::string DurationDescription() {

		std::string desc = std::to_string(StartingTime) + ":00 - " + std::to_string(EndingTime) + ":00";

		return desc;
	}

	std::string EventDescription() {

		return Description;
	}


};