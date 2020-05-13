#pragma once /// UPDATERS

#include <functional>

/**
 * If you want to change some object dynamically
 * inherit from this class and use the given function that takes
 * a some object by reference to change it
 */
template<typename T>
class ColorUpdater
{
private:
    using FType = std::function<void(T&)>;

protected:
    ColorUpdater();

    ColorUpdater(const FType& func);

    FType col_updater_;

    static FType kDefault;
};

template<typename T>
ColorUpdater<T>::FType ColorUpdater<T>::kDefault = [ ]( T& ){ };

template<typename T>
ColorUpdater<T>::ColorUpdater(const FType& func) : col_updater_( func )
{}

template<typename T>
ColorUpdater<T>::ColorUpdater() : col_updater_( kDefault )
{}