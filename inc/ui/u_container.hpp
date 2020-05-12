#ifndef INC_UI_CONTAINER_
#define INC_UI_CONTAINER_

#include <vector>
#include <memory>

#include "u_element.hpp"
#include "a_definitions.hpp"

/**
 * Container class, by derivating it.
 * It's main goal is to be used as acontainer of UIelements,
 * the class derivating it representing a container (a menu, a screen etc).
 * This class SHOULD NEVER BE INSTANCIATED, only derived.
 */
class UiContainer
{
private:
protected:
    std::vector <std::shared_ptr<UiElement>> element_list;
    
public:
    UiContainer();

    /// Add some UiElement to the Window
    void AddUiElementToList(const SharedPtr<UiElement>& ptr);

    /// Deletes all the UiElement from the Window
    void ClearAllUiElements();
};

#endif // INC_UI_CONTAINER_