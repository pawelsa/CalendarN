#pragma once
#include "Event.h"
#include <string>
#include <list>
#include <iostream>
#include <vector>


extern sf::RenderWindow window;

class Day
{
public:


	Day(int dayNumber): NameOfDay(dim::DayNames.at(dayNumber)), DayNumber(dayNumber) { 
		
		if (dayNumber == 5) {

			Event eventToAdd = Event(12, 13, "test", Person("ee", "bb"));
			AddEvent(eventToAdd);
			Event eventToAd = Event(10, 11, "test1", Person("ee", "bb"));
			AddEvent(eventToAd);
		}
	
	
	};


	~Day() { }


	void AddEvent(Event eventToAdd)
	{
		try
		{
			EventList.push_back(eventToAdd);
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning adding event" << ex.what() << std::endl;
		}
	};

	void RemoveEvent(Event eventToRemove)
	{
		auto tempList = this->EventList;
		try
		{
			//std::vector<int> vec;
			//// .. put in some values ..
			//int int_to_remove = n;
			//vec.erase(std::remove(vec.begin(), vec.end(), int_to_remove), vec.end());

			tempList.erase(std::remove(tempList.begin(), tempList.end(), eventToRemove), tempList.end());
			this->EventList = tempList;
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning removing event" << ex.what() << std::endl;
		}
	}

	bool HaveAnyEvent()
	{
		if (EventList.size() == 0)
			return false;
		else
			return true;
	};


	void display_Day() {

		sf::Text EventName;
		EventName.setPosition(dim::NoEventsTextPosition_Day);
		EventName.setFont(dim::font);
		EventName.setCharacterSize(dim::NoEventTextSize_Day);
		EventName.setFillColor(sf::Color::White);

		if (EventList.empty()) {

			EventName.setString("No events");

			window.draw(EventName);
		}
		else {

			//EventName.setString()

			EventName.setCharacterSize(dim::EventTextSize_Day);
			EventName.setFillColor(sf::Color::Black);

			sf::RectangleShape Item;

			Item.setSize(dim::SizeOfItem_Day);
			Item.setFillColor(sf::Color::Green);

			sf::Text EventTime;

			EventTime.setFont(dim::font);
			EventTime.setCharacterSize(dim::EventTextSize_Day);
			EventTime.setFillColor(sf::Color::Black);

			sf::Vector2f position;

			for (int i = 0; i < EventList.size(); i++) {

				position = dim::ItemOffset_Day + sf::Vector2f(0, i*dim::OffsetBetweenItems_Day.y);

				Item.setPosition(position);
				EventTime.setPosition(position + dim::TextOffset_Day);
				EventName.setPosition(position + dim::TextOffset_Day + dim::TextNameEventOffset_Day);

				EventTime.setString(EventList.at(i).DurationDescription());
				EventName.setString(EventList.at(i).EventDescription());

				window.draw(Item);
				window.draw(EventTime);
				window.draw(EventName);
			}

		}

	}


private:


	std::vector<Event> EventList;

	const std::string NameOfDay;
	const int DayNumber;
};