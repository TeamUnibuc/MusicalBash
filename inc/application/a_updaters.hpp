#pragma once /// UPDATERS

#include <functional>

/**
 * If you want to change some object dynamically
 * inherit from this class and use the given function that takes
 * a some object by reference to change it
 */
template<typename T>
class ObjUpdater
{
private:
    using FType = std::function<void(T&)>;

protected:
    static const FType kDefault;

    ObjUpdater(const FType& func = kDefault) : col_updater_(func)
    { }

    FType col_updater_;
};

template <typename T>
const ObjUpdater<T>::FType ObjUpdater<T>::kDefault = [ ]( T& ){ };