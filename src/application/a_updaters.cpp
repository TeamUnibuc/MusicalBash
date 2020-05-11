#include "a_updaters.hpp"

ColorUpdater::FType ColorUpdater::kDefault = [ ]( sf::Color& ){ };

ColorUpdater::ColorUpdater(const FType& func) : col_updater_( func )
{}

ColorUpdater::ColorUpdater() : col_updater_( kDefault )
{}