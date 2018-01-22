#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Dimensions.h"
#include "Month.h"

extern sf::RenderWindow window;

class Year {

	const int YearNumber;
	std::vector<Month*> Months;

public:
	Year(int mYear) :YearNumber(mYear) {
		for (int i = 0; i < 12; i++)
		{
			//Commented means - mved to month
			//auto current = DayNumber(1, i, mYear);

			Month* monthToAdd = new Month(i, mYear/*, current*/);
			Months.push_back(monthToAdd);
		}
	}

	void displayYear() {

		sf::RectangleShape item;

		item.setSize(dim::SizeOfItem_Year);
		item.setFillColor(sf::Color::Transparent);
		item.setOutlineThickness(dim::OutlineThickness_Year);
		item.setOutlineColor(sf::Color::White);


		sf::Text NumberOfMonths_Text;

		NumberOfMonths_Text.setFont(dim::font);
		NumberOfMonths_Text.setFillColor(sf::Color::White);
		NumberOfMonths_Text.setCharacterSize(dim::TextSize_Year);


		for (int Y = 0; Y < 3; Y++) {

			for (int X = 0; X < 4; X++) {

				sf::Vector2f position = dim::ItemOffset_Year;
				position += sf::Vector2f(X*dim::OffsetBetweenItems_Year.x, Y*dim::OffsetBetweenItems_Year.y);

				item.setPosition(position);
				NumberOfMonths_Text.setPosition(position + dim::TextOffset_Year);

				NumberOfMonths_Text.setString(dim::MonthNames.at(Y * 4 + X));

				window.draw(item);
				window.draw(NumberOfMonths_Text);
			}

		}

	}

	Month* doTheyIntersect_Year(sf::Vector2f mPosition) {

		sf::RectangleShape item;

		item.setSize(dim::SizeOfItem_Year);

		for (int Y = 0; Y < 3; Y++) {

			for (int X = 0; X < 4; X++) {

				sf::Vector2f position = dim::ItemOffset_Year;
				position += sf::Vector2f(X*dim::OffsetBetweenItems_Year.x, Y*dim::OffsetBetweenItems_Year.y);

				item.setPosition(position);

				if (item.getGlobalBounds().contains(mPosition)) {

					return Months.at(Y * 4 + X);
				}
			}
		}
		return NULL;
	}	
};
