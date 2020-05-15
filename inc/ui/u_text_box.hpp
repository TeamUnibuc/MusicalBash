#ifndef INC_UI_TEXT_BOX_
#define INC_UI_TEXT_BOX_

#include "u_element.hpp"
#include "a_constants.hpp"

/*
 *  Class able to draw a text box
 *  It can store text either to the left, middle, or right of its box
 *  It only knows to render the text correctly and cut it and add "..." if it is too long
 */
class TextBox: public UiElement
{
private:
    const int sizeX_;
    const int sizeY_;
    int alignment_;

    sf::Text text_;

    bool show_dots_;
    
protected:

public:

    /*
     *  Create a text box by specifying posX and posY (relative to its container)
     *      width, height and alignment
     *  Mode can be one of the following 3:
     *    0. left-aligned
     *    1. centered
     *    2. right-aligned
     *  If the value for alignment is not valid, it defaults to 0
     */
    TextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string textInput, bool showDots = true);

    /*
     * Function for setting the text inside the TextBox
     * It will set the right font size to fit vertically and it will crop the text if it is too long
     * It is currently set up to take up 70% of the vertical space
     */
    void SetText(std::string textInput);

    /// Helper function to get the text content of the TextBox
    std::string GetText() const;

    /* Helper function to set the alignment of the TextBox
     * If the value given is not valid, it won't change anything
     */
    void SetAlignment(int alignment);

    /// Helper function to set the color of the TextBox
    void SetColor(sf::Color color);

    /// Function used to render the TextBox
    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;

    /// Function used to do updates that affect the TextBox
    void Update(int off_x, int off_y) override;

    /// Watch out to properly override this!!
    int GetHeight() const override;

    /// Watch out to properly override this!!
    int GetWidth() const override;

};

#endif // INC_UI_TEXT_BOX