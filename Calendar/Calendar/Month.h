#pragma once
#include "Week.h"
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

	Month(std::string nameOfMonth, int monthNumber)
	{
		this->Name = nameOfMonth;
		this->Number = monthNumber;
	};

	~Month();

	std::list<Week*> Weeks;
	std::string Name;
	int Number;

};