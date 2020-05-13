#pragma once /// ALBUM ENTRY HPP

#include "u_png_color_button.hpp"
#include "c_delete_album.hpp"
#include "c_show_specific_album.hpp"
#include "u_text_box.hpp"

class AlbumEntry : public UiElement
{
private:
    SharedPtr<PAlbum> album_ptr_;
    
    PngSprite      del_btn_sprite_;
    ColorButton    col_btn_;
    ColorButton    del_btn_;

    int number_;


    int GetHeight() const override;
    int GetWidth()  const override;

    void SetPosition(const std::pair<int,int>& pos) = delete;

    static const int   kEntryWidth;
    static const int   kButtonWidth;
    static const int   kHeight;
    static const int   kActualHeight;
    static const int   kGap;
    static const int   kSpriteOffset;
    static const float kHeightRatio;

    static const std::pair<int, int> kColBtnPos;
    static const std::pair<int, int> kDelBtnPos;

    static const std::pair<int, int> kColBtnSize;
    static const std::pair<int, int> kDelBtnSize;

public:
    AlbumEntry(SharedPtr<PAlbum> album_ptr, int number);
    
    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};