#pragma once
#include <SFML/Graphics.hpp>
#include<headers/game_objects.hpp>
#include <headers/game_engine.hpp>
namespace Game
{
    class Player
    {
    private:
    public:
        void play(Game::GamePostion &_pos, sf::RenderWindow &_window)
        {
            while (true)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    auto mousePos = sf::Mouse::getPosition(_window);
                    mousePos.x /= (WINDOW_DIMENSION / 3);
                    mousePos.y /= (WINDOW_DIMENSION / 3);
                    if (_pos.grid[mousePos.y][mousePos.x] not_eq EMPTY)
                        continue;
                    else
                    {
                        _pos.grid[mousePos.y][mousePos.x] = CROSS;
                        break;
                    }
                }
            }
        }
    };
}