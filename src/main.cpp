#include <SFML/Graphics.hpp>
#include <headers/game_objects.hpp>
#ifndef WINDOW_DIMENSION
#define WINDOW_DIMENSION 800.f
#endif
int main(int argc, char const *argv[])
{
    // init the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_DIMENSION, WINDOW_DIMENSION), "Tic Tac Toe");
    window.setFramerateLimit(1);

    Board board;
    Dot dot(2, 2);
    Cross cross(1,2);

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
        dot.draw(window);
        cross.draw(window);
        window.display();
    }
    return 0;
}