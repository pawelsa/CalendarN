#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Dimensions.h"

extern sf::RenderWindow window;

class Year {



	const int YearNumber;
	

public:

	Year(int mYear) :YearNumber(mYear) {





	}



	int returnYear() {

		return YearNumber;
	}




};
