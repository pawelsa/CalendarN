#pragma once
#include <iostream>
class Person {
	std::string FirstName, LastName;
public:
	Person();
	Person(std::string firstname,std::string lastname)
	{
		this->FirstName = firstname;
		this->FirstName = lastname;
	}
	~Person();
};