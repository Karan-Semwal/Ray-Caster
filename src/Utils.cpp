#include "Utils.h"

inline constexpr double PI = 3.14f;

float lerpValue(float currentValue, float targetValue, float interpolationPoint)
{
    currentValue += interpolationPoint;
    if (currentValue > targetValue) {
        return targetValue;
    }
    return currentValue;
}

sf::Vector2f operator+(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    sf::Vector2f resultPlus;
    resultPlus.x = v1.x + v2.x;
    resultPlus.y = v1.y + v2.y;
    return resultPlus;
}

sf::Vector2f operator-(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    sf::Vector2f resultMinus;
    resultMinus.x = v1.x - v2.x;
    resultMinus.y = v1.y - v2.y;
    return resultMinus;
}

sf::Vector2f operator*(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    sf::Vector2f resultMult;
    resultMult.x = v1.x * v2.x;
    resultMult.y = v1.y * v2.y;
    return resultMult;
}

sf::Vector2f operator+(const sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x + n;
    resultDiv.y = v.y + n;
    return resultDiv;
}

sf::Vector2f operator-(const sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x - n;
    resultDiv.y = v.y - n;
    return resultDiv;
}

sf::Vector2f operator*(const sf::Vector2f& v, float n)
{
    sf::Vector2f result;
    result.x = v.x * n;
    result.y = v.y * n;
    return result;
}

sf::Vector2f operator/(const sf::Vector2f& v, float n)
{
    sf::Vector2f resultDiv;
    resultDiv.x = v.x / n;
    resultDiv.y = v.y / n;
    return resultDiv;
}

sf::Vector2f normalize(const sf::Vector2f& v)
{
    float mag = std::sqrt((v.x) * (v.x) + (v.y) * (v.y));
    sf::Vector2f dir(v.x / mag, v.y / mag);
    return dir;
}

float DegToRadian(float degree)
{
    float radianValue = degree * PI / 180.0f;
    return radianValue;
}

int randomInteger(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

sf::Vector2f randomVector2f(int min, int max)
{
    sf::Vector2f dir;
    dir.x = (float)randomInteger(min, max);
    dir.y = (sf::Uint8)randomInteger(min, max);
    return dir;
}

void operator<<(std::ostream& os, sf::Vector2f v)
{
    os << v.x << ", " << v.y << std::endl;
}

sf::Color randomColor() {
    sf::Color color;
    color.r = (sf::Uint8)randomInteger(0, 255);
    color.g = (sf::Uint8)randomInteger(0, 255);
    color.b = (sf::Uint8)randomInteger(0, 255);
    return color;
}

bool isWithinWindow(const sf::Vector2f& position, sf::RenderWindow& window)
{
    int wWidth  = window.getSize().x;
    int wHeight = window.getSize().y;
    
    if (position.x > 0 && position.y > 0) {
        if (position.x < wWidth && position.y < wHeight)
            return true;
    }
    return false;
}

float magnitude(const sf::Vector2f& start, const sf::Vector2f& end)
{
    sf::Vector2f diff = end - start;
    float magnitude = std::sqrt(diff.x * diff.x + diff.y * diff.y);
    return magnitude;
}