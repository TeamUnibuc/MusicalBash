#pragma once  /// UI_U_BUTTON_HPP_

#include "u_element.hpp"
#include "a_constants.hpp"
#include "command.hpp"
#include "a_knowledge.hpp"
#include "a_utils.hpp"

/**
 * Button class that has a size and 
 * holds a command to execute on click
*/
class Button : public UiElement
{
protected:
    int sizeX_, sizeY_;

    UniquePtr<Command> command_;

    bool ThisButtonClicked(int off_x, int off_y) const;

public:
    bool ThisButtonHovered(int off_x, int off_y) const;

    Button(int szX, int szY, UniquePtr<Command> cPtr);

    void Update(int off_x, int off_y);

    int GetHeight() const;

    int GetWidth() const;
};