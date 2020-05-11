#pragma once /// Music Entry HPP

#include "u_color_button.hpp"
#include "c_add_music_queue.hpp"
#include "u_text_box.hpp"
#include "a_utils.hpp"

class MusicEntry : public UiElement
{
private:
protected:
    int size_x_, size_y_;

    ColorButton col_btn_;

    SharedPtr<PMusic> music_;

    static const float kPercentage;
    static const float kHeightRatio;
    static const int   kMinSpaceForDuration;
    static const float kTextScale;

public:
    MusicEntry(int szX, int szY, 
               sf::Color normal, sf::Color hovered, SharedPtr<PMusic> mPtr);

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;

    void Update(int off_x, int off_y) override;

    int GetHeight() const override;
    int GetWidth() const override;
};