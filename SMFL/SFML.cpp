// SMFL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "MouseFollower.h"

#define RADIUS 10.f
#define FPS 60
#define MS_PER_FRAME 1000/FPS
#define SPEED 5

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600,900), "SFML works!");
	MouseFollower follower(RADIUS, SPEED);
	
	sf::Clock timer;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time start = timer.getElapsedTime();
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

		window.clear();

		follower.Update(1./FPS);

		follower.Render(window);

		window.display();

		sf::sleep( start + sf::milliseconds(MS_PER_FRAME) - timer.getElapsedTime() );
	}

	return 0;
}