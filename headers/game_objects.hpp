#pragma once
#include <SFML/Graphics.hpp>
class Board
{
private:
    sf::RectangleShape m_horizontalDivider, m_verticalDivider;

public:
    void draw(sf::RenderWindow &_window)
    {
        _window.draw(m_horizontalDivider);
        _window.draw(m_verticalDivider);
    }
};
class Cross
{
private:
    const float m_armLength, m_armWidth;

private:
    sf::RectangleShape m_frontIncliningArm{{m_armLength, m_armWidth}}, m_backIncliningArm{{m_armLength, m_armWidth}};

public:
    void draw(sf::RenderWindow &_window)
    {
        _window.draw(m_frontIncliningArm);
        _window.draw(m_backIncliningArm);
    }
};