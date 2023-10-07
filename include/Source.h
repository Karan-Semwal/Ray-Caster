#pragma once
#include <vector>
#include "Ray.h"

class Source
{
public:
	Source(const sf::Vector2f& startPos);
	~Source();

	void update(const sf::VertexArray& lineSegment, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);

private:
	void init(const sf::Vector2f& startPos);

private:
	std::vector<Ray> m_rays;
};

