#include "u_scrollable_list.hpp"

ScrollableList::ScrollableList(int sizeX, int sizeY) :
    sizeX_(sizeX), sizeY_(sizeY), start_index_(0)
{}

void ScrollableList::AddUiElement(SharedPtr<UiElement> ptr)
{
    if (ptr->GetWidth() > sizeX_ || ptr->GetHeight() > sizeY_)
        throw std::runtime_error("Trying to add UiElement bigger than allocated space for father ScrollableList");
    element_list.push_back(ptr);
}

void ScrollableList::SetStartIndex(int index)
{
    if (index < 0)
        throw std::runtime_error("Trying to set negative start index to scrolable list Ui Element");
    start_index_ = index;
}

void ScrollableList::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    int used_vertical = 0, index = start_index_;
    while (index < (int)element_list.size() && element_list[index]->GetHeight() + used_vertical <= sizeY_) {
        element_list[index]->Render(rw, off_x + pos_x, off_y + pos_y + used_vertical);
        used_vertical += element_list[index]->GetHeight();
        ++index;
    }
}

void ScrollableList::Update(int off_x, int off_y)
{
    sf::Event ev = EventHandler::GetEvent();
    if (ev.type == sf::Event::MouseWheelScrolled) {
        auto mpoz = EventHandler::GetMousePoz();
        int x = mpoz.first - off_x;
        int y = mpoz.second - off_y;
        std::cerr << "Position: " << x << ' ' << y << '\n';
        if (x >= pos_x && x < pos_x + sizeX_ && y >= pos_y && y < pos_y + sizeY_) {
            int delta = ev.mouseWheelScroll.delta;
            std::cerr << "Scrollable List detected to be scrolled!\n";
            std::cerr << "Delta: " << delta << '\n';
            if (delta > 0)
                start_index_ = std::min((int)element_list.size() - 1, start_index_ + 1);
            else if (delta < 0 )
                start_index_ = std::max(0, start_index_ - 1);
        }
    }
}

/// Watch out to properly override this!!
int ScrollableList::GetHeight() const
{
    return sizeY_;
}

/// Watch out to properly override this!!
int ScrollableList::GetWidth() const
{
    return sizeX_;
}