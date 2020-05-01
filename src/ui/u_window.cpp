#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int off_x, int off_y) :
    size_x(sz_x),
    size_y(sz_y),
    off_x(off_x),
    off_y(off_y)
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
        ptr_el->Render(rw, off_x + offX, off_y + offY);
    }
}

void Window::Update(int offX, int offY)
{
    for (auto ptr_el : element_list) {
        ptr_el->Update(off_x + offX, off_y + offY);
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