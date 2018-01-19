#pragma once
#include "Day.h"
#include <string.h>

extern sf::RenderWindow window;

class Month
{
public:
	Month() {};
	Month(std::string nameOfMonth)
	{
		this->Name = nameOfMonth;
	};

	Month(std::string nameOfMonth, int monthNumber, int year, int firstDay)
	{
		this->Name = nameOfMonth;
		this->Number = monthNumber;
		this->NumberOfDaysInMonth = NumberOfDays(monthNumber, year);
		FirstDayOfMonth = firstDay;

		int Counter = firstDay;
		
		for (int i = 0; i < NumberOfDaysInMonth; i++)
		{
			Day* dayToAdd = new Day(Counter);
			Counter++;
			if (Counter == 7)
			{
				Counter = 0;
			}
			Days.push_back(dayToAdd);

		}
	};


	void displayMonth() {


		sf::RectangleShape item;

		item.setSize(dim::sizeOfItem_Month);
		item.setFillColor(sf::Color::Transparent);
		item.setOutlineThickness(3);


		sf::Text NumberOfMonth_Text;

		NumberOfMonth_Text.setFont(dim::font);
		NumberOfMonth_Text.setFillColor(sf::Color::White);
		NumberOfMonth_Text.setCharacterSize(17);


		int CountNumberOfDays = 1;


		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					//if (/*	Day.at(CountNumberOfDays)->isEvent()	*/) {

						//item.setFillColor(sf::Color(130, 0, 0));
					//}


					sf::Vector2f position = sf::Vector2f(dim::itemOffset_Month.x + X * (dim::OffestBetweenItems_Month.x),
						dim::itemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y));

					item.setPosition(position);
					NumberOfMonth_Text.setPosition(position + sf::Vector2f(15, 15));

					NumberOfMonth_Text.setString(std::to_string(CountNumberOfDays));
					CountNumberOfDays++;

					window.draw(item);
					window.draw(NumberOfMonth_Text);
				}
			}

		}


	}


	bool doTheyIntersect_Month(sf::Vector2f mPosition) {

		sf::RectangleShape item;

		item.setSize(dim::sizeOfItem_Month);

		int CountNumberOfDays = 1;


		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					sf::Vector2f position = sf::Vector2f(dim::itemOffset_Month.x + X * (dim::OffestBetweenItems_Month.x),
														dim::itemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y));

					item.setPosition(position);

					if (item.getGlobalBounds().contains(mPosition)) {

						return true;
					}

					CountNumberOfDays++;
				}
			}

		}

		return false;
	}



	~Month();

private:

	std::list<Day*> Days;
	std::string Name;
	int NumberOfDaysInMonth;
	int Number;
	int FirstDayOfMonth;

	int NumberOfDays(int monthNumber, int year)
	{
		// January
		if (monthNumber == 0)
			return (31);

		// February
		if (monthNumber == 1)
		{
			// If the year is leap then February has
			// 29 days
			if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
				return (29);
			else
				return (28);
		}

		// March
		if (monthNumber == 2)
			return (31);

		// April
		if (monthNumber == 3)
			return (30);

		// May
		if (monthNumber == 4)
			return (31);

		// June
		if (monthNumber == 5)
			return (30);

		// July
		if (monthNumber == 6)
			return (31);

		// August
		if (monthNumber == 7)
			return (31);

		// September
		if (monthNumber == 8)
			return (30);

		// October
		if (monthNumber == 9)
			return (31);

		// November
		if (monthNumber == 10)
			return (30);

		// December
		if (monthNumber == 11)
			return (31);
	}
};