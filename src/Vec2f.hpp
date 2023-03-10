#ifndef __VEC2F_RPS_GAME
#define __VEC2F_RPS_GAME

#include <SFML/System/Vector2.hpp>
#include <cmath>

class Vec2f : public sf::Vector2f
{
public:
    Vec2f();
    Vec2f(sf::Vector2f vec);
    Vec2f(float x, float y);
    float magnitude();
    Vec2f normalize();
    friend Vec2f operator-(const Vec2f& f1, const Vec2f& f2);
    friend Vec2f operator+(const Vec2f& f1, const Vec2f& f2);
};


#endif