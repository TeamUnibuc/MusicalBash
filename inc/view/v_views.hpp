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
    /// Height of the Title for each View Name as text at the top of the window
    static const int kTitleHeight;
    /// Height of the scrollable list from just below the title to the end
    static const int kListHeight;

    static const int kListWidthSimple;
    static const int kListWidthButtons;
    static const int kEntryHeight;

    static const std::pair<int,int> kListPoz;

public:
    static void CreateHome(UiContainer *const father, UiElement *const fatherUi);
    static void UpdateHome(UiContainer *const father, UiElement *const fatherUi);

    static void CreateQueue(UiContainer *const father, UiElement *const fatherUi);
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