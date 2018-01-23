#pragma once
#include <SFML\Graphics.hpp>
#include "Dimensions.h"
#include "Person.h"

extern sf::RenderWindow window;

struct EventHelper {

	int day;
	int month;
	int year;

	//	Event
	int StartingTime, EndingTime;
	std::string Description;
	Person Man;

	//	LongTernEvent
	int LastingTime;	//	PeriodLasting

	//	PeriodicEvent
	int Period;

	bool TypeOfEvent[2];
	bool ActiveInputBox[8];

public:

	EventHelper() {

		TypeOfEvent[0] = false;
		TypeOfEvent[1] = false;

		for (int i = 0; i < 8; i++)
			ActiveInputBox[i] = false;

	}


	void display() {

		sf::RectangleShape Item;

		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		if (TypeOfEvent[0] == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Item);

		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper+dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		if (TypeOfEvent[1] == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Item);



	}

	void intersection(sf::Vector2f mousePos) {

		sf::RectangleShape Item;

		Item.setPosition(dim::CheckBoxOffset_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			TypeOfEvent[0] = !TypeOfEvent[0];

			if (TypeOfEvent[0] == TypeOfEvent[1]) {
				TypeOfEvent[1] = !TypeOfEvent[1];
			}
		}

		Item.setPosition(dim::CheckBoxOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			TypeOfEvent[1] = !TypeOfEvent[1];

			if (TypeOfEvent[1] == TypeOfEvent[0]) {
				TypeOfEvent[0] = !TypeOfEvent[0];
			}
		}


	}

};
