#include <SFML/Graphics.hpp>
#include "Source.h"
#include <vector>

int main()
{
	sf::RenderWindow window(sf::VideoMode(32 * 16 * 2, 32 * 9 * 2), "Ray Casting", sf::Style::Close);
	window.setMouseCursorVisible(false);

	sf::Vector2f start{ window.getSize().x / 2.f, window.getSize().y / 2.f };

	sf::Vector2f p1(550.f, 200.f);
	sf::Vector2f p2(500.f, 400.f);
	sf::VertexArray wall(sf::Lines, 2);
	wall[0].position = p1;
	wall[1].position = p2;

	Source source(start);

	while (window.isOpen())
	{
		sf::Event event;
		if (window.hasFocus())
		{
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}

			source.update(wall, window);

			// render
			window.clear();
			window.draw(wall);
			source.render(window);
			window.display();
		}
	}
}