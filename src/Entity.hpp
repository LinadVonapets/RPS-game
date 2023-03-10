#ifndef __ENTITY_RPS_GAME
#define __ENTITY_RPS_GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vec2f.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <functional>
#include <algorithm>

extern const sf::FloatRect g_window_rect;


class Entity: public sf::Drawable
{
public:
    enum Type
    {
        ROCK,
        PAPER,
        SCISSORS,
        ALL
    };
    struct Pair
    {
        Type type;
        sf::FloatRect rect;
    };

private:    
    float m_speed = 0.6;
    static inline std::vector<Entity::Pair> table{};
    static inline int m_id_counter{0};

    static inline std::array<sf::Texture, Type::ALL> m_texturebuffers;
    sf::Sprite m_sprite;
    
    static inline std::array<sf::SoundBuffer, Type::ALL> m_soundbuffers;
    sf::Sound m_sound;

    int m_id;

    Vec2f m_direction;
    Type m_type;
    Vec2f m_pos;
    
public:
    Entity(Type type);
    Entity(const Entity& value);
    void update();
    void setPos(float x, float y);
    void setPos(Vec2f pos);  
    static void loadMedia();
    
private:
    Vec2f get_mate_direction();
    void update_table();
    bool collide(const sf::FloatRect& rect) const;
    void collisions_with_walls(char direct);    
    void move();
    void check_captured();
    void update_direction();
    Vec2f get_direction(bool hunter_flag);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif