// SMFL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "MouseFollower.h"
#include "LerpMoveTo.h"
#include "SpringMoveTo.h"

#define FPS 60
#define MS_PER_FRAME 1000/FPS

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600,900), "SFML works!");
	//LerpMoveTo locomotion(5);
	SpringMoveTo locomotion(110, 10);
	MouseFollower follower(10.f, &locomotion);
	
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