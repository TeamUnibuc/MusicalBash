#pragma once /// VIEW_VIEWS_HPP_

#include "u_scrollable_list.hpp"
#include "u_song_text_box.hpp"
#include "u_music_entry.hpp"
#include "a_button_factory.hpp"
#include "u_dynamic_text_box.hpp"
#include "u_progress_bar.hpp"

/**
 * ViewsMain is a class that has logic for populating different views
 * for the Main window. Here we can find hard coded values for drawing on screen
 * like positions, sizes, colors, etc.  So that we don't overpopulate the constants namespace
 */
class ViewsMain
{
private:

protected:
    static const int kListWidthSimple;
    static const int kListWidthButtons;
    static const int kListHeight;
    static const int kEntryHeight;

    static const std::pair<int,int> kListPoz;

public:
    static void Home();

    static void CreateQueue(UiContainer * const father_elem_list);
    static void UpdateQueue(SharedPtr<ScrollableList> l_ptr, const std::vector<SharedPtr<PMusic>>& music_list);
};

class ViewsSide
{
protected:

public:
    static void Create(UiContainer *const father_elem);
};

class ViewsStatus
{
protected:

public:
    static void Create(UiContainer *const father_elem);
};