#include "Calendar.h"



	sf::RenderWindow window(sf::VideoMode(dim::WindowSize.x, dim::WindowSize.y), "Calendar");



int main() {




	while (window.isOpen())
	{

		Calendar *newCalendar = new Calendar();
		Month *newMonth = new Month(5, 2018);
		//Year *newYear = new Year(2018);
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == sf::Event::MouseButtonPressed) {

				sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

				/*if (newCalendar->doTheyIntersect_Calendar(mousePosition)) {

					std::cout << "TAK!\n";
				}*/

				/*if (newMonth->doTheyIntersect_Month(mousePosition)) {

					std::cout << "TAK!\n";
				}*/

				/*if (newYear->doTheyIntersect_Year(mousePosition)) {

					std::cout << "TAK!\n";
				}*/
			}


		}

		window.clear();

		//newCalendar->display_Calendar();
		newMonth->displayMonth();
		//newYear->displayYear();

		window.display();
	}

	return 0;





}