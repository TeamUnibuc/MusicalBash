#include "u_element.hpp"

UiElement::~UiElement()
{}

UiElement::UiElement() : pos_x(0), pos_y(0)
{}

UiElement::UiElement(int pos_x, int pos_y) :
    pos_x(pos_x),
    pos_y(pos_y)
{}
