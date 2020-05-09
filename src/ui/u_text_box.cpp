#include "u_text_box.hpp"

TextBox::TextBox(int posX, int posY, int sizeX, int sizeY, int alignment, std::string textInput):
    UiElement(posX, posY), sizeX_(sizeX), sizeY_(sizeY)
{
    if (alignment < 0 || alignment > 2)
        alignment_ = 0;
    else
        alignment_ = alignment; 

    /// Viewing the bounding rectangle
    // border.setSize(sf::Vector2f(sizeX, sizeY));
    // border.setOutlineColor(sf::Color::Blue);
    // border.setFillColor(sf::Color::Transparent);
    // border.setOutlineThickness(-1);

    text_.setFont(Constants::kFont);
    this->SetText(textInput);
}

void TextBox::SetText(std::string textInput)
{
    text_.setString(textInput);
    sf::FloatRect textBounds = text_.getLocalBounds();
    
    /// We want it to occupy 80% of the TextBox height
    text_.setCharacterSize(0.7 * sizeY_);

    textBounds = text_.getLocalBounds();

    /// Currently, L characters occupy W pixels horizontally, so W / L pixels per character
    /// We want there to be at most MX_W pixels, so at most L * MX_W / H characters
    /// Multiply 0.9 to add a bit of padding to the left and to the right
    uint character_limit = textInput.size() * (sizeX_ * 0.9) / textBounds.width;
    if (textInput.size() > character_limit)
        textInput = textInput.substr(0, character_limit - 3) + "...";
    text_.setString(textInput);
}

void TextBox::Render(sf::RenderWindow& rw, int off_x, int off_y)
{
    /// Only for testing purposes
    // border.setPosition(off_x + pos_x, off_y + pos_y);
    // rw.draw(border);

    sf::FloatRect textBounds = text_.getLocalBounds();
    int alignment_offset = 0.01 * sizeX_;
    if (alignment_ == 0)
        alignment_offset += 0;
    else if (alignment_ == 1)
        alignment_offset += 0.5 * (sizeX_ - textBounds.width);
    else
        alignment_offset += sizeX_ - textBounds.width - 2 * alignment_offset;
    

    text_.setPosition(off_x + pos_x + alignment_offset, off_y + pos_y);
    rw.draw(text_);
}

void TextBox::SetAlignment(int alignment)
{
    if (alignment < 0 || alignment > 2)
        return;
    alignment_ = alignment;
}

void TextBox::SetColor(sf::Color color)
{
    text_.setFillColor(color);
}

void TextBox::Update(int /* off_x */, int /* off_y */)
{
    return;
}

int TextBox::GetHeight() const
{
    return sizeY_;
}

int TextBox::GetWidth() const
{
    return sizeX_;
}