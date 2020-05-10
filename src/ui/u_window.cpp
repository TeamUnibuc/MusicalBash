#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int off_x, int off_y, Window::Type w_type) :
    size_x(sz_x),
    size_y(sz_y),
    g_off_x(off_x),
    g_off_y(off_y),
    type_(w_type)
{
    w_view_.reset(sf::FloatRect(off_x, off_y, size_x, size_y));
}

int Window::GetWidth() const
{
    return size_x;
} 

int Window::GetHeight() const
{
    return size_y;
} 

void Window::setViewPort(const sf::FloatRect& viewRect)
{
    w_view_.setViewport(viewRect);
}

void Window::Render(sf::RenderWindow& rw, int offX, int offY)
{
    for (auto ptr_el : element_list) {
        ptr_el->Render(rw, g_off_x + offX, g_off_y + offY);
    }
}

void Window::Update(int offX, int offY)
{
    switch (type_)
    {
        case Type::Main : {
            MainController(offX, offY);
            return;
        }
        case Type::Side : {
            SideController(offX, offY);
            return;
        }
        case Type::Status : {
            StatusController(offX, offY);
            return;
        }
    }

    throw bad_behaviour("Controller not existent for this Window type!");
}

void Window::AddSampleUiElement(std::shared_ptr<UiElement> ptr)
{
    element_list.push_back(ptr);
}

void Window::ClearAllElements()
{
    element_list.clear();
}

/// =============== Controllers =====================

void Window::MainController(int /* off_x */, int /* off_y */)
{
    namespace Kld = Knowledge;

    Logger::Get() << " | Prev State: ";
    Logger::PrintEnum(prev_state);
    Logger::Get() << '\n';

    switch (Knowledge::curr)
    {
    case Constants::State::W::Queue:
        /// If change of state then create the TextBox and ScrollableList
        if (prev_state != Constants::State::W::Queue) {
            element_list.clear();

            auto txt_ptr = std::make_unique<TextBox>(
                5, 5, 700, 30, 1, "Current Queue"
            );
            element_list.push_back(std::move(txt_ptr));

            auto lst_ptr = std::make_unique<ScrollableList>(
                700, 500
            );
            lst_ptr->SetPosition({5, 35});
            element_list.push_back(std::move(lst_ptr));

            Logger::Get() << " - Added A ScrList and a TextButton to Main window\n";

            prev_state = Constants::State::W::Queue;
        }
        /// find the ScrollableList in elements_list
        SharedPtr<ScrollableList> ptr;
        int dbg_cnt = 0;
        for (auto p : element_list) {
            if (dynamic_cast<ScrollableList*>(&*p)) {
                ptr = std::dynamic_pointer_cast<ScrollableList>(p);
                ++dbg_cnt;
            }
        }
        Logger::Get() << "Found  - " << dbg_cnt << " - ScrollableList elements in Container\n";

        Knowledge::curr = Constants::State::W::Queue;

        break;
    }
}


void Window::SideController(int off_x, int off_y)
{
    for (auto ptr : element_list)
        ptr->Update(off_x, off_y);
}

void Window::StatusController(int off_x, int off_y)
{
    for (auto ptr : element_list)
        ptr->Update(off_x, off_y);
}

}