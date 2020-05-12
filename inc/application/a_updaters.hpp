#pragma once /// UPDATERS

#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

/**
 * If you want to change some sf::Color dynamically
 * inherit from this class and use the given function that takes
 * a sf::Color by reference to change it
 */
class ColorUpdater
{
private:
    using FType = std::function<void(sf::Color&)>;

protected:
    ColorUpdater();

    ColorUpdater(const FType& func);

    FType col_updater_;

public:
    static FType kDefault;

};