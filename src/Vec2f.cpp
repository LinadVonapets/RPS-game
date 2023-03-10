#include "Vec2f.hpp"
Vec2f::Vec2f()
    :sf::Vector2f()
{
}


Vec2f::Vec2f(sf::Vector2f vec)
    :sf::Vector2f(vec)
{
}


Vec2f::Vec2f(float x, float y)
    :sf::Vector2f(x,y)
{
}


float Vec2f::magnitude()
{
    return sqrt(this->x * this->x + this->y * this->y);
}


Vec2f Vec2f::normalize()
{
    return Vec2f(this->x / magnitude(), this->y / magnitude());
}


// friend functions
Vec2f operator-(const Vec2f& f1, const Vec2f& f2)
{
    return sf::Vector2f(f1.x, f1.y) - sf::Vector2f(f2.x, f2.y);
}


Vec2f operator+(const Vec2f& f1, const Vec2f& f2)
{
    return sf::Vector2f(f1.x, f1.y) + sf::Vector2f(f2.x, f2.y);
}

