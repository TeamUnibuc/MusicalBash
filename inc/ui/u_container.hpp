#ifndef INC_UI_CONTAINER_
#define INC_UI_CONTAINER_

#include <vector>
#include <memory>

#include "u_element.hpp"

class UiContainer
{
private:
protected:
public:
    UiContainer();

    std::vector <std::shared_ptr<UiElement>> element_list;

    /// Was thinking to make it recursive, but cmon, there is no real use for this
    // std::vector <UiContainer> container_list;
};

#endif // INC_UI_CONTAINER_