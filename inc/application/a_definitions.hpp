#pragma once

#include <memory>

// Useful typedefs we will use throughout the code
template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T>
using UniquePtr = std::unique_ptr<T>;

template <typename T>
using WeakPtr = std::weak_ptr<T>;

namespace Constants 
{
    /// States saying what should each window should look for in each frame
    /// Also used to see if we need to rebuild the structure of the Music::Window
    namespace State
    {
        enum class W
        {
            Home,
            Playlists,
            ViewPlaylist,
            Albums,
            ViewAlbum,
            Queue,
            Import,
            Create,

            None
        };
    }
}