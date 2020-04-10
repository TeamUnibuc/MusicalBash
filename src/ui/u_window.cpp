#include "u_window.hpp"

namespace Musical
{

Window::Window(int sz_x, int sz_y, const std::vector<Constants::State>& pos_states) :
    size_x(sz_x),
    size_y(sz_y),
    possible_states(pos_states)
{}

int Window::GetWidth() const
{
    return size_x;
} 

int Window::GetHeight() const
{
    return size_y;
} 

void Window::SetWatchOver(float vLeft, float vTop, float vWidth, float vHeight)
{
    w_view_.reset(sf::FloatRect(vLeft, vTop, vWidth, vHeight));
}

void Window::setViewPort(const sf::FloatRect& viewRect)
{
    w_view_.setViewport(viewRect);
}

void Window::Redraw(sf::RenderWindow& rw, int offset_x)
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