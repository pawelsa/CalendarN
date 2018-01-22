#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Year.h"
#include <time.h>

extern sf::RenderWindow window;

class Calendar {

	/*			Variables used to display items				*/


	std::vector<Year*> YearList;

	int BeginYear;


public:

	Calendar() {

		//	Load font
		try {
			if (!dim::font.loadFromFile("arial.ttf")) {

				throw "Error. Cannot load font !";
			}
		}
		catch (char *e) {

			std::cout << e;
		}


		//	Get current Year
		
		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);

		BeginYear = aTime->tm_year + 1899;


		for (int i = BeginYear; i < BeginYear+4; i++) {

			YearList.push_back(new Year(i));
		}

	}


	void display_Calendar() {


		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Calendar);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(5);
		

		sf::Text NumberOfYears_Text;

		NumberOfYears_Text.setFont(dim::font);
		NumberOfYears_Text.setCharacterSize(dim::TextSize_Calendar);
		NumberOfYears_Text.setFillColor(sf::Color::White);


		int MaxAmountOfItemsOnScreen = (window.getSize().y / dim::SizeOfItem_Calendar.y) - 1;
				
		sf::Color to_alpha = sf::Color::White;
		to_alpha.a = 135;


		for (int i = 0; i <= MaxAmountOfItemsOnScreen; i++) {

			sf::Vector2f position = dim::ItemOffset_Calendar + sf::Vector2f(0, i*dim::OffsetBetweenItems_Calendar.y);

			Item.setPosition(position);

			NumberOfYears_Text.setPosition(position + dim::TextOffset_Calendar);
			NumberOfYears_Text.setString(std::to_string(BeginYear + i));


			if (i == 0 || i == MaxAmountOfItemsOnScreen) {

				NumberOfYears_Text.setFillColor(to_alpha);
				Item.setOutlineColor(to_alpha);
			}
			else {

				NumberOfYears_Text.setFillColor(sf::Color::White);
				Item.setOutlineColor(sf::Color::White);
			}

			window.draw(Item);
			window.draw(NumberOfYears_Text);
		}
		
		//	Draws black bar around screen

		sf::Vector2f SizeOfBlackOutliner = (sf::Vector2f) dim::WindowSize - sf::Vector2f(2 * dim::ThicknessOfBlackOutliner, 2*dim::ThicknessOfBlackOutliner);

		Item.setPosition(sf::Vector2f(dim::ThicknessOfBlackOutliner, dim::ThicknessOfBlackOutliner));
		Item.setSize(SizeOfBlackOutliner);
		Item.setOutlineThickness(dim::ThicknessOfBlackOutliner);
		Item.setOutlineColor(sf::Color::Black);
		Item.setFillColor(sf::Color::Transparent);

		window.draw(Item);

		//Konrad's button xD
		sf::RectangleShape Button;

		Button.setSize(dim::SizeOfButton);
		Button.setFillColor(sf::Color::Yellow);
		Button.setOutlineThickness(5);
		Button.setPosition(dim::ButtonOffset);
		Button.setOutlineColor(sf::Color::Blue);

		window.draw(Button);
	}


	bool doTheyIntersect_Calendar (sf::Vector2f  mPosition) {

		sf::RectangleShape Item;
		Item.setSize(dim::SizeOfItem_Calendar);

		sf::Vector2f position;

		for (int i = 0; i <= YearList.size(); i++) {

			position = dim::ItemOffset_Calendar + sf::Vector2f(0, i*dim::OffsetBetweenItems_Calendar.y);
			
			Item.setPosition(position);

			if (Item.getGlobalBounds().contains(mPosition)) {

				return true;
			}

		}


		return false;
	}


};