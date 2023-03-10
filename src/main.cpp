#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vec2f.hpp"
#include "Entity.hpp"
#include "EntityGroupSystem.hpp"

const sf::FloatRect g_window_rect(0,0,800,600);


int main()
{   

    sf::RenderWindow win(sf::VideoMode(g_window_rect.width,g_window_rect.height), "rps_life");
    sf::Event event;
    win.setVerticalSyncEnabled(true);
    
    Entity::loadMedia();
    
    EntityGroupSystem EGS(20, 20, 20, {100, 300}, {350, 100}, {700, 400}, 250);

    while(win.isOpen())
    {
        while(win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color::White);

        EGS.update();
        win.draw(EGS);
        
        win.display();
    }
}