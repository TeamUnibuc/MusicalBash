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
    auto ev = Knowledge::GetEvent();
    if (ev.type == sf::Event::MouseWheelScrolled) {
        auto mpoz = Knowledge::GetMousePoz();

        auto [x, y] = std::pair(mpoz.first - off_x, mpoz.second - off_y);
        
        Logger::Get() << "Position: " << x << ' ' << y << '\n';
        if (x >= pos_x && x < pos_x + sizeX_ && y >= pos_y && y < pos_y + sizeY_) {
            int delta = ev.mouseWheelScroll.delta;
            Logger::Get() << "Scroll with Delta: " << delta << '\n';

            if (delta < 0) {
                if (not LastElementIsVisible(start_index_))
                    start_index_ = std::min((int)element_list.size() - 1, start_index_ + 1);
            }
            else if (delta > 0 )
                start_index_ = std::max(0, start_index_ - 1);
        }
    }
    else {
        int used_vertical = 0, index = start_index_;
        while (index < (int)element_list.size() && element_list[index]->GetHeight() + used_vertical <= sizeY_) {
            element_list[index]->Update(off_x + pos_x, off_y + pos_y + used_vertical);
            
            used_vertical += element_list[index]->GetHeight();
            ++index;
        }
    }
}

bool ScrollableList::LastElementIsVisible(int start) const
{
    int used_vertical = 0;
    while (start < (int)element_list.size() && element_list[start]->GetHeight() + used_vertical <= sizeY_) {        
        used_vertical += element_list[start]->GetHeight();
        ++start;
    }
    return start == (int)element_list.size();
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