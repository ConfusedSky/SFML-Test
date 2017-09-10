// SMFL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "MouseFollower.h"
#include "LerpMoveTo.h"
#include "SpringMoveTo.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600,900), "SFML works!");
	//LerpMoveTo locomotion(5);
	SpringMoveTo locomotion(110, 10);
	MouseFollower follower(10.f, &locomotion);
	
	sf::Clock timer;
	int previous = timer.getElapsedTime().asMilliseconds();
	int lag = 0;

	while (window.isOpen())
	{
		int current = timer.getElapsedTime().asMilliseconds();
		int elapsed = current - previous;
		previous = current;
		lag += elapsed;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseMoved)
			{
				sf::Event::MouseMoveEvent moved = event.mouseMove;
				follower.ChangeTarget(
					window.mapPixelToCoords(
						sf::Vector2i(moved.x, moved.y)
					) );
			}
		}

		while (lag >= MS_PER_FRAME)
		{
			follower.Update(1.f / FPS);
			lag -= MS_PER_FRAME;
		}

		window.clear();

		follower.Render(window, lag / 1000.f);

		window.display();
	}

	return 0;
}