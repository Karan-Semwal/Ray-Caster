#pragma once
#include <SFML/Graphics.hpp>

class Ray
{
public:
	Ray(const sf::Vector2f& startPos, float angle);
	~Ray();

	bool intersectsLineSeg(const sf::VertexArray& lineSegment);
	void update(const sf::VertexArray& lineSegment);
	void render(sf::RenderWindow& window);

	const sf::Vector2f& getDir() const { return m_dir; }

	void setStart(const sf::Vector2f& startPos) { m_start = startPos; }
	void setEnd(const sf::Vector2f& endPos) { m_end = endPos; }
	void setColor(const sf::Color& color) 
	{
		m_ray[0].color = color; 
		m_ray[1].color = color;
	}

public:
	const float c_scale = 1500.f;

private:
	float           m_angle;
	sf::Vector2f	m_start;
	sf::Vector2f	m_end;
	sf::Vector2f	m_dir;
	sf::VertexArray m_ray;
};

