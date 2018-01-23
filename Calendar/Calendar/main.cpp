#include "Controller.h"



	sf::RenderWindow window(sf::VideoMode(dim::WindowSize.x, dim::WindowSize.y), "Calendar");



int main() {

	Controller *newController = new Controller;


	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == sf::Event::MouseButtonPressed) {

				sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

				newController->intersection(mousePosition);

			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{

					newController->moveToLastScreen();
				}
				else {

					newController->enterChar(static_cast<char>(event.key.code));
				}
			}

		}

		window.clear();

		newController->display();

		window.display();
	}

	return 0;





}