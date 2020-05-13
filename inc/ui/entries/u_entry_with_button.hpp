#pragma once /// UI ENTRY WITH BUTTON

#include <utility>

/**
 * Abstract class that holds Constants for dusplaying 
 * AlbumEntry, PlaylistEntry
 */
class EntryWithButton
{
protected:

    static const int   kEntryWidth;
    static const int   kButtonWidth;
    static const int   kHeight;
    static const int   kActualHeight;
    static const int   kGap;
    static const int   kSpriteOffset;
    static const float kHeightRatio;

    static const std::pair<int, int> kColBtnPos;
    static const std::pair<int, int> kDelBtnPos;

    static const std::pair<int, int> kColBtnSize;
    static const std::pair<int, int> kDelBtnSize;


public:
};