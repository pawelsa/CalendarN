#include "Calendar.h"



	sf::RenderWindow window(sf::VideoMode(1280, 720), "Calendar");



int main() {




	while (window.isOpen())
	{

		Calendar *newCalendar = new Calendar();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == sf::Event::MouseButtonPressed) {

				sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

				if (newCalendar->doTheyIntersect(mousePosition)) {

					std::cout << "TAK!\n";
				}
			}


		}

		window.clear();

		newCalendar->display();

		window.display();
	}

	return 0;





}