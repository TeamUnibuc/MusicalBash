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
            MainController(offX + g_off_x, offY + g_off_y);
            return;
        }
        case Type::Side : {
            SideController(offX + g_off_x, offY + g_off_y);
            return;
        }
        case Type::Status : {
            StatusController(offX + g_off_x, offY + g_off_y);
            return;
        }
    }

    throw bad_behaviour("Controller not existent for this Window type!");
}

/// =============== Controllers =====================

void Window::MainController(int off_x, int off_y)
{
    namespace Kld = Knowledge;

    if (prev_state != Knowledge::curr_state) {
        Logger::Get() << " | Prev State: ";
        Logger::PrintEnum(prev_state);
        Logger::Get() << "\n";
    }

    switch (Knowledge::curr_state)
    {  /// ==== Main ==================  Queue  ==========================
    case Constants::State::W::Queue: {
        /// If change of state then create the TextBox and ScrollableList
        if (prev_state != Knowledge::curr_state) {
            Logger::Get() << "  New state:  Queue\n";

            element_list.clear();

            ViewsMain::CreateQueue(this);
        }
        SharedPtr<ScrollableList> scrl_ptr;

        for (auto p : element_list) 
            if (dynamic_cast<ScrollableList*>(&*p))
                scrl_ptr = std::dynamic_pointer_cast<ScrollableList>(p);

        scrl_ptr->ClearAllUiElements();

        ViewsMain::UpdateQueue(scrl_ptr, Knowledge::Daddy_Player->GetPlayingQueue());

        Knowledge::curr_state = Constants::State::W::Queue;
        break;
    }  ///// ===== Main ============= Home =====================
    case Constants::State::W::Home :
    {
        if (prev_state != Knowledge::curr_state) {
            Logger::Get() << "  New state:  Home\n";

            element_list.clear();
        }

        Knowledge::curr_state = Constants::State::W::Home;


        break;
    }

    /// Next case here

    }

    /// Finally update the elements contained in this window
    for (auto p : element_list)
        p->Update(off_x, off_y);

    prev_state = Knowledge::curr_state;
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