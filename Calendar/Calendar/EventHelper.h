#pragma once
#include <SFML\Graphics.hpp>
#include "Dimensions.h"
#include "Person.h"

extern sf::RenderWindow window;

class EventHelper {


	//	Event
	std::string day, month, year, StartingTime, EndingTime;
	std::string Description;	

	Person Man;		//	nie wiem co z tym

	//	LongTernEvent
	std::string LastingTime;	//	PeriodLasting

	//	PeriodicEvent
	std::string Period;

	bool TypeOfEvent[2];
	bool ActiveInputBox[8];


	/*		Active input box			
	*
	*	1	-	Description
	*	2	-	Day
	*	3	-	Month
	*	4	-	Year
	*	5	-	StartingTime
	*	6	-	EndingTime
	*	7	-	LastingTime
	*	8	-	Period
	*
	*/

public:

	EventHelper() {

		TypeOfEvent[0] = false;
		TypeOfEvent[1] = false;

		for (int i = 0; i < 8; i++)
			ActiveInputBox[i] = false;

	}


	void display() {

		/*			CheckBoxes															*/

		sf::RectangleShape Item;

		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		sf::Text Text;

		Text.setFont(dim::font);
		Text.setPosition(dim::CheckBoxOffset_Helper + dim::CheckBoxTextOffset_Helper);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::CheckBoxTextSize_Helper);

		Text.setString("Long term");

		if (TypeOfEvent[0] == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Text);
		window.draw(Item);

		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper+dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::CheckBoxOffset_Helper + dim::CheckBoxTextOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper);

		Text.setString("Periodic");

		if (TypeOfEvent[1] == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Text);
		window.draw(Item);


		/*			Input Text Box														*/

		Item.setPosition(dim::DescriptionBoxOffset_Helper);
		Item.setSize(dim::SizeOfDescriptionBox_Helper);
		Item.setOutlineThickness(dim::OutlineThicknessDescriptionBox_Helper);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::DescriptionBoxOffset_Helper + dim::TextDescriptionBoxOffset_Helper);
		Text.setCharacterSize(dim::TextSizeDescriptionBox_Helper);
		Text.setString(Description);

		window.draw(Item);
		window.draw(Text);

		/*
		
		tu trzeba dodac prostokaty na date dd/mm/yyyy
		i potem jesli jest wybrane periodic albo longlasting to musi wyswietlic kolejne prostokaciki
		
		*/

	}

	void intersection(sf::Vector2f mousePos) {

		sf::RectangleShape Item;

		Item.setPosition(dim::CheckBoxOffset_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);


		if (Item.getGlobalBounds().contains(mousePos)) {

			if (TypeOfEvent[0] == true) {

				TypeOfEvent[0] = !TypeOfEvent[0];
			}
			else if(TypeOfEvent[0] == false) {

				TypeOfEvent[0] = true;
				TypeOfEvent[1] = false;
			}

			return;
		}

		Item.setPosition(dim::CheckBoxOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			if (TypeOfEvent[1] == true) {

				TypeOfEvent[1] = !TypeOfEvent[1];
			}
			else if (TypeOfEvent[1] == false) {

				TypeOfEvent[1] = true;
				TypeOfEvent[0] = false;
			}
		}

		//	Check if DescriptionBox Selected

		Item.setPosition(dim::DescriptionBoxOffset_Helper);
		Item.setSize(dim::SizeOfDescriptionBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 8; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[0] = true;
		}
		else {

			ActiveInputBox[0] = false;
		}

	}

	void enterChar(int c) {

		/*		Active input box
		*
		*	0	-	Description
		*	1	-	Day
		*	2	-	Month
		*	3	-	Year
		*	4	-	StartingTime
		*	5	-	EndingTime
		*	6	-	LastingTime
		*	7	-	Period
		*
		*/

		char add=-1;

		if (c <= 35) {

			add = 0;
			add = (char)c + 65;
		}
		else if (c == 57) {

			add = -3;
		}
		else if (c == 59) {

			add = -2;	//backspace
		}

		if (ActiveInputBox[0]) {

			if (add >=0)
				Description += add;
			if (add == -2) {

				int length = Description.length();
				Description = Description.substr(0, Description.size() - 1);
			}
			if (add == -3) {

				Description += " ";
			}
		}
		if (ActiveInputBox[1]) {

			if (add > 26) {
				day += add;
			}
			if (add == -2) {

				int length = Description.length();
				day = day.substr(0, day.size() - 1);
			}
			if (add == -3) {

				day += " ";
			}

		}
		if (ActiveInputBox[2]) {

			if (add > 26) {
				month += add;
			}
			if (add == -2) {

				int length = Description.length();
				month = month.substr(0, month.size() - 1);
			}
			if (add == -3) {

				month += " ";
			}

		}
		if (ActiveInputBox[3]) {

			if (add > 26) {
				year += add;
			}
			if (add == -2) {

				int length = Description.length();
				year = year.substr(0, year.size() - 1);
			}
			if (add == -3) {

				year += " ";
			}

		}
		if (ActiveInputBox[4]) {

			if (add > 26) {
				StartingTime += add;
			}
			if (add == -2) {

				int length = Description.length();
				StartingTime = StartingTime.substr(0, StartingTime.size() - 1);
			}
			if (add == -3) {

				StartingTime += " ";
			}

		}
		if (ActiveInputBox[5]) {

			if (add > 26) {
				EndingTime += add;
			}
			if (add == -2) {

				int length = Description.length();
				EndingTime = EndingTime.substr(0, EndingTime.size() - 1);
			}
			if (add == -3) {

				EndingTime += " ";
			}

		}
		if (ActiveInputBox[6]) {

			if (add > 26) {
				LastingTime += add;
			}
			if (add == -2) {

				int length = Description.length();
				LastingTime = LastingTime.substr(0, LastingTime.size() - 1);
			}
			if (add == -3) {

				LastingTime += " ";
			}

		}
		if (ActiveInputBox[7]) {

			if (add > 26) {
				Period += add;
			}
			if (add == -2) {

				int length = Description.length();
				Period = Period.substr(0, Period.size() - 1);
			}
			if (add == -3) {

				Period += " ";
			}

		}
	}

};
