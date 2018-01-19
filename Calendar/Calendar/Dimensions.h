#pragma once
#include <SFML/Graphics.hpp>

namespace dim {


	sf::Font font;


	std::vector<std::string> MonthNames = { "January", "February", "March", "April", "May", "June", "July", "August" , "September" , "October" , "November" , "December" };


	std::vector<std::string> DayNames = { "Monday", "Tjuzdej", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

		/*	
		*	
		*	*	Item is basically the square which is printed in every view
		*	
		*	*	ItemOffset is offset from the upper left corner of window to first square (Item)
		*	
		*	*	TextOffset is offset of a text from the upper left corner of square (Item)
		*	
		*	*	OffsetBetweenItems distance between two squares (Items) 
		*			it consists of SizeOfItem and OutlineThickness
		*	
		*/


	/*			RenderWindow											*/

	const sf::Vector2u WindowSize = sf::Vector2u(1280, 720);

	/*			Calendar class											*/

	const sf::Vector2f SizeOfItem_Calendar = sf::Vector2f(150, 150);
	const sf::Vector2f ItemOffset_Calendar = sf::Vector2f(120, 10);
	const sf::Vector2f OffsetBetweenItems_Calendar = sf::Vector2f(0, 170);
	const sf::Vector2f TextOffset_Calendar = sf::Vector2f(25, 25);
	const int ThicknessOfBlackOutliner = 100;
	const int TextSize_Calendar = 25;

	/*			Year class												*/

	const sf::Vector2f SizeOfItem_Year = sf::Vector2f(150, 150);
	const sf::Vector2f ItemOffset_Year = sf::Vector2f(340, 135);
	const int OutlineThickness_Year = 5;
	const sf::Vector2f OffsetBetweenItems_Year = SizeOfItem_Year + sf::Vector2f(OutlineThickness_Year, OutlineThickness_Year);
	const sf::Vector2f TextOffset_Year = sf::Vector2f(18, 18);
	const int TextSize_Year = 17;

	/*			Month class												*/

	const sf::Vector2f SizeOfItem_Month = sf::Vector2f(100, 100);
	const sf::Vector2f ItemOffset_Month = sf::Vector2f(300, 100);
	const int OutlineThickness_Month = 3;
	const sf::Vector2f OffestBetweenItems_Month = SizeOfItem_Month + sf::Vector2f(OutlineThickness_Month, OutlineThickness_Month);
	const sf::Vector2f TextOffset_Month = sf::Vector2f(15, 15);
	const int TextSize_Month = 17;


}