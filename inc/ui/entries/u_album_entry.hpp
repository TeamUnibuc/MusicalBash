#pragma once /// ALBUM ENTRY HPP

#include "u_png_color_button.hpp"
#include "c_delete_album.hpp"
#include "u_text_box.hpp"

class AlbumEntry : public UiElement
{
private:
    SharedPtr<PAlbum> album_ptr_;
    
    PngColorButton del_btn_;
    ColorButton    col_btn_;

    int number_;


    int GetHeight() const override;
    int GetWidth()  const override;

    void SetPosition(const std::pair<int,int>& pos) = delete;

    static const int   kEntryWidth;
    static const int   kButtonWidth;
    static const int   kHeight;
    static const int   kActualHeight;
    static const int   kGap;
    static const float kHeightRatio;

public:
    AlbumEntry(int posX, int posY, sf::Color normal, sf::Color hovered,
               SharedPtr<PAlbum> album_ptr, int number, 
               UniquePtr<Command> c_ptr, SharedPtr<PngSprite> png_ptr);
    
    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};