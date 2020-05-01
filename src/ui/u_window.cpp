#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, int off_x, int off_y) :
    size_x_(sz_x),
    size_y_(sz_y),
    off_y_(off_y),
    off_x_(off_x)
{
    w_view_.reset(sf::FloatRect(off_x, off_y, size_x_, size_y_));
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

void Window::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    off_x += off_x_;
    off_y += off_y_;
    for (auto ptr_el : element_list) {
        ptr_el->Render(rw, off_x, off_y);
    }
}

void Window::Update(int off_x, int off_y)
{
    off_x += off_x_;
    off_y += off_y_;
    for (auto ptr_el : element_list) {
        ptr_el->Update(off_x, off_y);
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