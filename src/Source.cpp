#include "Source.h"
#include "Utils.h"

Source::Source(const sf::Vector2f& startPos)
{
	m_rays.reserve(360 / 0.05);
	init(startPos);
}

Source::~Source()
{
}

void Source::init(const sf::Vector2f& startPos)
{
	for (float i = 0; i <= 360; i += 0.05f)
	{
		Ray ray{ startPos, float(i) };
		ray.setEnd(startPos + ray.getDir() * ray.c_scale);
		m_rays.emplace_back(ray);
	}
}

void Source::update(const sf::VertexArray& lineSegment, sf::RenderWindow& window)
{
	sf::Vector2f mousePos{ (float)sf::Mouse::getPosition(window).x,
					       (float)sf::Mouse::getPosition(window).y };
	
	for (auto& ray : m_rays) 
	{
		if (isWithinWindow(mousePos, window)) {
			ray.setStart(mousePos);;
		}
		ray.update(lineSegment);
	}
}

void Source::render(sf::RenderWindow& window)
{
	for (auto& ray : m_rays) {
		ray.render(window);
	}
}
