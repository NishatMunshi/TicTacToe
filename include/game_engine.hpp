#pragma once
#include <vector>
namespace Game
{
    enum CellState
    {
        DOT = -1,
        EMPTY,
        CROSS
    };
    enum Eval
    {
        DOTWON = -1,
        DRAW,
        CROSSWON
    };
    class GamePostion
    {
    public:
        Eval eval;
        CellState grid[3][3];
        // void print(void) const
        // {
        //     for (auto &row : grid)
        //     {
        //         for (auto &cell : row)
        //         {
        //             std::cout << cell << '\t';
        //         }
        //         std::cout << '\n';
        //     }
        //     std::cout<<'\n';
        // }
        GamePostion(void)
        {
            for (auto &row : grid)
            {
                for (auto &cell : row)
                {
                    cell = EMPTY;
                }
            }
        }
        bool isGameOver(void) const
        {
            bool noMoreCells = true;
            for (auto &row : grid)
            {
                for (auto &cell : row)
                {
                    if (cell == EMPTY)
                        noMoreCells = false;
                }
            }
            if (noMoreCells)
                return true;
            for (auto &row : grid)
            {
                if (row[0] == row[1] and row[1] == row[2] and row[0] not_eq EMPTY)
                    return true;
            }
            for (unsigned columnIndex = 0u; columnIndex < 3u; columnIndex++)
            {
                for (unsigned rowIndex = 0u; rowIndex < 3u; rowIndex++)
                {
                    if (grid[0][columnIndex] == grid[1][columnIndex] and grid[1][columnIndex] == grid[2][columnIndex] and grid[0][columnIndex] not_eq EMPTY)
                        return true;
                }
            }
            if (grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2] and grid[0][0] not_eq EMPTY)
                return true;
            if (grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0] and grid[0][2] not_eq EMPTY)
                return true;
            return false;
        }
        Eval staticEval(void) const //  only call this when gameover
        {
            for (auto &row : grid)
            {
                if (row[0] == row[1] and row[1] == row[2] and row[0] == DOT)
                    return DOTWON;
                else if (row[0] == row[1] and row[1] == row[2] and row[0] == CROSS)
                    return CROSSWON;
            }
            for (unsigned columnIndex = 0u; columnIndex < 3u; columnIndex++)
            {
                for (unsigned rowIndex = 0u; rowIndex < 3u; rowIndex++)
                {
                    if (grid[0][columnIndex] == grid[1][columnIndex] and grid[1][columnIndex] == grid[2][columnIndex] and grid[0][columnIndex] == DOT)
                        return DOTWON;
                    else if (grid[0][columnIndex] == grid[1][columnIndex] and grid[1][columnIndex] == grid[2][columnIndex] and grid[0][columnIndex] == CROSS)
                        return CROSSWON;
                }
            }
            if (grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2] and grid[0][0] == DOT)
                return DOTWON;
            else if (grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2] and grid[0][0] == CROSS)
                return CROSSWON;
            if (grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0] and grid[0][2] == DOT)
                return DOTWON;
            else if (grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0] and grid[0][2] == CROSS)
                return CROSSWON;
            return DRAW;
        }
        void get_children(const CellState _whoseTurn, std::vector<GamePostion> &_children) const
        {
            GamePostion tempPos = *this;
            for (auto &row : tempPos.grid)
            {
                for (auto &cell : row)
                {
                    if (cell == EMPTY)
                    {
                        cell = _whoseTurn;
                        _children.push_back(tempPos);
                        cell = EMPTY;
                    }
                }
            }
        }
    };
    class Engine
    {
    private:
        inline auto min(const Eval _first, const Eval _second) const
        {
            return _first <= _second ? _first : _second;
        }
        inline auto max(const Eval _first, const Eval _second) const
        {
            return _first >= _second ? _first : _second;
        }
        Eval m_minimax(const GamePostion &_parent, bool _dotPLayersTurn)
        {
            if (_parent.isGameOver())
            {
                return _parent.staticEval();
            }
            else if (_dotPLayersTurn)
            {
                std::vector<GamePostion> children;
                _parent.get_children(DOT, children);
                Eval eval = CROSSWON;
                for (auto &child : children)
                {
                    eval = min(m_minimax(child, false), eval);
                }
                return eval;
            }
            else
            {
                std::vector<GamePostion> children;
                _parent.get_children(CROSS, children);
                Eval eval = DOTWON;
                for (auto &child : children)
                {
                    eval = max(m_minimax(child, true), eval);
                }
                return eval;
            }
        }

    public:
        void play(GamePostion &_position)
        {
            std::vector<GamePostion> children;
            _position.get_children(DOT, children);
            for (auto &child : children)
            {
                child.eval = m_minimax(child, false);
            }
            _position.eval = m_minimax(_position, true);
            for (auto &child : children)
            {
                if (child.eval == _position.eval)
                {
                    _position = child;
                    return;
                }
            }
        }
    };
}