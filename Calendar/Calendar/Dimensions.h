#pragma once
#include <SFML/Graphics.hpp>

namespace dim {


	sf::Font font;
	
	
	/*			Year class											*/

	const sf::Vector2f sizeOfItem_Year = sf::Vector2f(150, 150);
	const sf::Vector2f textOffset_Year = sf::Vector2f(25, 25);
	const sf::Vector2f itemOffset_Year = sf::Vector2f(120, 10);
	const int NumberSizeInYear = 25;

	/*			Month class											*/

	const sf::Vector2f sizeOfItem_Month = sf::Vector2f(100, 100);
	const sf::Vector2f itemOffset_Month = sf::Vector2f(300, 100);
	const sf::Vector2f OffestBetweenItems_Month = sf::Vector2f(103, 103);


}