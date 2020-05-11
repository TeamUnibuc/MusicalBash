#include "u_container.hpp"

UiContainer::UiContainer()
{}

void UiContainer::AddUiElementToList(const SharedPtr<UiElement>& ptr)
{
    element_list.push_back(ptr);
}

void UiContainer::ClearAllUiElements()
{
    element_list.clear();
}