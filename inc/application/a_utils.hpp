#pragma once

#include <utility>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "a_logger.hpp"

namespace Utils
{
    bool PointInsideRect(std::pair<int,int> mpoz, int topLeftX, int topLeftY, int szX, int szY);

    std::string IntToMinSecondSecond(int time);

    sf::Color RandomColor();
}