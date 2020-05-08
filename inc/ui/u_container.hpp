#ifndef INC_UI_CONTAINER_
#define INC_UI_CONTAINER_

#include <vector>
#include <memory>

#include "u_element.hpp"

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
public:
    UiContainer();

    std::vector <std::shared_ptr<UiElement>> element_list;
};

#endif // INC_UI_CONTAINER_