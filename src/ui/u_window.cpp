#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int offset_x) :
    size_x_(sz_x),
    size_y_(sz_y),
    offset_x_(offset_x)
{
    w_view_.reset(sf::FloatRect(offset_x, 0, size_x_, size_y_));
}

int Window::GetWidth() const
{
    return size_x_;
} 

int Window::GetHeight() const
{
    return size_y_;
} 

void Window::setViewPort(const sf::FloatRect& viewRect)
{
    w_view_.setViewport(viewRect);
}

void Window::Redraw(sf::RenderWindow& rw)
{
    for (auto ptr_el : element_list) {
        ptr_el->Render(rw, offset_x_);
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