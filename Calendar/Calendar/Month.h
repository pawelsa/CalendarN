#pragma once
#include "Day.h"
#include <string.h>

extern sf::RenderWindow window;

class Month
{
public:

	/*
	Month(int monthNumber): Name(dim::MonthNames.at(monthNumber)), Number(monthNumber)
	{
	};
	*/

	Month(int monthNumber, int year) :Name(dim::MonthNames.at(monthNumber)), Number(monthNumber), // monthNumber+1??
		NumberOfDaysInMonth(NumberOfDays(monthNumber, year)), FirstDayOfMonth(DayNumber(1, monthNumber, year))
	{
		/*
		this->Name = dim::MonthNames.at(monthNumber);
		this->Number = monthNumber;
		this->NumberOfDaysInMonth = NumberOfDays(monthNumber, year);
		FirstDayOfMonth = DayNumber(1, monthNumber, year);*/

		int Counter = FirstDayOfMonth;


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


		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Month);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(dim::OutlineThickness_Month);


		sf::Text NumberOfMonthsDay_Text;

		NumberOfMonthsDay_Text.setFont(dim::font);
		NumberOfMonthsDay_Text.setFillColor(sf::Color::White);
		NumberOfMonthsDay_Text.setCharacterSize(dim::TextSize_Month);


		for (int i = 0; i < 7; i++) {

			NumberOfMonthsDay_Text.setPosition(dim::DayNamesOffset + sf::Vector2f(i*dim::OffestBetweenItems_Month.x, 0));
			NumberOfMonthsDay_Text.setString(dim::DayNames.at(i));

			window.draw(NumberOfMonthsDay_Text);
		}


		int CountNumberOfDays = 1;


		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					if (Days.at(CountNumberOfDays-1)->HaveAnyEvent()) {

						Item.setFillColor(sf::Color(130, 0, 0));
					}
					else {

						Item.setFillColor(sf::Color::Transparent);
					}


					sf::Vector2f position = sf::Vector2f(dim::ItemOffset_Month.x + X * (dim::OffestBetweenItems_Month.x),
						dim::ItemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y));

					Item.setPosition(position);
					NumberOfMonthsDay_Text.setPosition(position + dim::TextOffset_Month);

					NumberOfMonthsDay_Text.setString(std::to_string(CountNumberOfDays));
					CountNumberOfDays++;

					window.draw(Item);
					window.draw(NumberOfMonthsDay_Text);
				}
			}

		}


	}


	bool doTheyIntersect_Month(sf::Vector2f mPosition) {

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Month);

		int CountNumberOfDays = 1;


		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					sf::Vector2f position = sf::Vector2f(dim::ItemOffset_Month.x + X * (dim::OffestBetweenItems_Month.x),
														dim::ItemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y));

					Item.setPosition(position);

					if (Item.getGlobalBounds().contains(mPosition)) {

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

	std::vector<Day*> Days;
	const std::string Name;
	const int NumberOfDaysInMonth;
	const int Number;
	const int FirstDayOfMonth;

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




	int DayNumber(int day, int month, int year)
	{

		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
			4, 6, 2, 4 };
		year -= month < 3;
		return (year + year / 4 - year / 100 +
			year / 400 + t[month - 1] + day) % 7;
	}
};