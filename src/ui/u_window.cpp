#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int offset_x,
               const std::vector<Constants::State>& pos_states) :
    size_x(sz_x),
    size_y(sz_y),
    offset_x(offset_x),
    possible_states(pos_states)
{
    w_view_.reset(sf::FloatRect(offset_x, 0, size_x, size_y));
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

void Window::Redraw(sf::RenderWindow& rw)
{
    for (auto ptr_el : element_list) {
        ptr_el->Render(rw, offset_x);
    }
}

void Window::AddSampleUiElement(std::shared_ptr<UiElement> ptr)
{
    element_list.push_back(ptr);
}

void Window::ClearAllElements()
{
    element_list.clear();
}

}