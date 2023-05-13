#pragma once
#include <SFML/Graphics.hpp>
#ifndef WINDOW_DIMENSION
#define WINDOW_DIMENSION 810.f
#endif
class Board
{
private:
    sf::RectangleShape m_horizontalDividers[4], m_verticalDividers[4];
    float m_dividerThickness = 30.f;

public:
    Board(void)
    {
        int i = 0;
        for (auto &divider : m_horizontalDividers)
        {
            divider.setSize({WINDOW_DIMENSION, m_dividerThickness});
            divider.setPosition({0.f, i * (WINDOW_DIMENSION - m_dividerThickness) / 3});
            i++;
        }
        int j = 0;
        for (auto &divider : m_verticalDividers)
        {
            divider.setSize({m_dividerThickness, WINDOW_DIMENSION});
            divider.setPosition({j * (WINDOW_DIMENSION - m_dividerThickness) / 3, 0.f});
            j++;
        }
    }

public: // inside loop
    void draw(sf::RenderWindow &_window)
    {
        for (auto &divider : m_horizontalDividers)
        {
            _window.draw(divider);
        }
        for (auto &divider : m_verticalDividers)
        {
            _window.draw(divider);
        }
    }
};
class Cross
{
private:
    const unsigned m_rowIndex, m_columnIndex;
    const float m_armLength = (WINDOW_DIMENSION / 3.f - 120.f) * 1.414f, m_armWidth = 30.f;
    sf::RectangleShape m_frontIncliningArm{{m_armLength, m_armWidth}}, m_backIncliningArm{{m_armLength, m_armWidth}};

public:
    Cross(const unsigned _rowIndex, const unsigned _columnIndex)
        : m_rowIndex(_rowIndex), m_columnIndex(_columnIndex)
    {
        m_frontIncliningArm.setRotation(135.f);
        m_backIncliningArm.setRotation(45.f);
        m_frontIncliningArm.setFillColor(sf::Color::Red);
        m_backIncliningArm.setFillColor(sf::Color::Red);
        m_frontIncliningArm.setPosition({m_columnIndex * (WINDOW_DIMENSION - 30.f) / 3.f + (WINDOW_DIMENSION - 30.f) / 3.f - 30.f, m_rowIndex * (WINDOW_DIMENSION - 30.f) / 3.f + 80.f});
        m_backIncliningArm.setPosition({m_columnIndex * (WINDOW_DIMENSION - 30.f) / 3.f + 85.f, m_rowIndex * (WINDOW_DIMENSION - 30.f) / 3.f + 60.f});
    }
    void draw(sf::RenderWindow &_window)
    {
        _window.draw(m_frontIncliningArm);
        _window.draw(m_backIncliningArm);
    }
};

class Dot
{
private:
    const unsigned m_rowIndex, m_columnIndex;
    const float m_radius = WINDOW_DIMENSION / 6 - 75;
    const float m_thickness = 30.f;
    sf::CircleShape m_shape{m_radius};

public:
    Dot(const unsigned _rowIndex, const unsigned _columnIndex)
        : m_rowIndex(_rowIndex), m_columnIndex(_columnIndex)
    {
        m_shape.setFillColor(sf::Color::Black);
        m_shape.setOutlineThickness(m_thickness);
        m_shape.setOutlineColor(sf::Color::Yellow);
        m_shape.setPosition({m_columnIndex * (WINDOW_DIMENSION - 30.f) / 3.f + 85.f, m_rowIndex * (WINDOW_DIMENSION - 30.f) / 3.f + 85.f});
    }
    void draw(sf::RenderWindow &_window)
    {
        _window.draw(m_shape);
    }
};