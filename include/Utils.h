#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

float lerpValue(float currentValue, float targetValue, float interpolationPoint);
sf::Vector2f operator+(const sf::Vector2f& v1, const sf::Vector2f& v2);
sf::Vector2f operator-(const sf::Vector2f& v1, const sf::Vector2f& v2);
sf::Vector2f operator*(const sf::Vector2f& v1, const sf::Vector2f& v2);
sf::Vector2f operator+(const sf::Vector2f& v, float n);
sf::Vector2f operator-(const sf::Vector2f& v, float n);
sf::Vector2f operator*(const sf::Vector2f& v, float n);
sf::Vector2f operator/(const sf::Vector2f& v, float n);
sf::Vector2f normalize(const sf::Vector2f& v);
sf::Vector2f randomVector2f(int min, int max);
float DegToRadian(float degree);
int randomInteger(int min, int max);
void operator<<(std::ostream& os, sf::Vector2f v);
sf::Color randomColor();
bool isWithinWindow(const sf::Vector2f& position, sf::RenderWindow& window);
float magnitude(const sf::Vector2f& start, const sf::Vector2f& end);

