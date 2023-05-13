#include <SFML/Graphics.hpp>
#include <headers/player.hpp>
#include <headers/game_engine.hpp>
#include <headers/game_objects.hpp>
#include <iostream>
#ifndef WINDOW_DIMENSION
#define WINDOW_DIMENSION 810.f
#endif

bool draw(const Game::GamePostion &_pos, sf::RenderWindow &_window)
{
    if (_pos.isGameOver())
        return false;
    for (unsigned rowIndex = 0; rowIndex < 3; rowIndex++)
    {
        for (unsigned columnIndex = 0; columnIndex < 3; columnIndex++)
        {
            if (_pos.grid[rowIndex][columnIndex] == Game::DOT)
            {
                Game::Dot dot(rowIndex, columnIndex);
                dot.draw(_window);
            }
            else if (_pos.grid[rowIndex][columnIndex] == Game::CROSS)
            {
                Game::Cross cross(rowIndex, columnIndex);
                cross.draw(_window);
            }
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    // init the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_DIMENSION, WINDOW_DIMENSION), "Tic Tac Toe");

    Game::Board board;
    Game::Player player;
    Game::Engine engine;
    Game::GamePostion pos;

    while (window.isOpen())
    {
        // event check
        sf::Event _event;
        while (window.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        board.draw(window);
        if (not draw(pos, window))
            return 0;
        window.display();


        player.play(pos, window);
        draw(pos, window);
        window.display();

        engine.play(pos);
        draw(pos, window);
        window.display();
    }
    return 0;
}