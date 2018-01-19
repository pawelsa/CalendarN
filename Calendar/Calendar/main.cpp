#include "Calendar.h"



	sf::RenderWindow window(sf::VideoMode(1280, 720), "Calendar");



int main() {




	while (window.isOpen())
	{

		Calendar *newCalendar = new Calendar();
		Month *newMonth = new Month("May", 5, 2018, 3);

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

				if (newMonth->doTheyIntersect_Month(mousePosition)) {

					std::cout << "TAK!\n";
				}
			}


		}

		window.clear();

		//newCalendar->display();
		newMonth->displayMonth();
		window.display();
	}

	return 0;





}