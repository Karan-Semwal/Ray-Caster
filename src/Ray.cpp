#include "Ray.h"
#include "Utils.h"
#include <cmath>

Ray::Ray(const sf::Vector2f& startPos, float angle)
	: m_start(startPos),
	  m_end{ c_scale, c_scale },
	  m_ray(sf::Lines, 2),
	  m_angle(angle)
{
	// angle in radians
	m_angle = m_angle * (3.14 / 180.f);

	// direction from angle
	m_dir = sf::Vector2f{ std::cos(m_angle), std::sin(m_angle) };

	// set color
	m_ray[0].position = m_start;
	m_ray[1].position = m_end;

	m_ray[0].color = sf::Color::White;
	m_ray[0].color.a = 40;
	
	m_ray[1].color = sf::Color::White;
	m_ray[1].color.a = 20;
}

Ray::~Ray()
{
}

void Ray::update(const sf::VertexArray& lineSegment)
{
	bool intersects = intersectsLineSeg(lineSegment);
	if (!intersects) {
		m_end = m_start + m_dir * c_scale;
	}

	m_ray[0].position = m_start;
	m_ray[1].position = m_end;
}

void Ray::render(sf::RenderWindow& window)
{
	window.draw(this->m_ray);
}

// check if a ray intersects with a line segment and get the intersection point
bool Ray::intersectsLineSeg(const sf::VertexArray& lineSegment) {
	sf::Vector2f p = m_start;
	sf::Vector2f q = lineSegment[0].position;
	sf::Vector2f s = lineSegment[1].position - q;

	// Calculate the cross product of the ray direction and line segment
	float cross = m_dir.x * s.y - m_dir.y * s.x;

	// Check if the ray and line segment are not parallel (cross != 0)
	if (std::abs(cross) > 1e-9) {
		sf::Vector2f qp = q - p;
		float t = (qp.x * s.y - qp.y * s.x) / cross;
		float u = (qp.x * m_dir.y - qp.y * m_dir.x) / cross;

		// Check if the intersection point is within the bounds of the line segment
		if (t >= 0.0f && u >= 0.0f && u <= 1.0f) 
		{
			m_end = p + t * m_dir; // intersection point
			return true;
		}
	}
	return false;
}