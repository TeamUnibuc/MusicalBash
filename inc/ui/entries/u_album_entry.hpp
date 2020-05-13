#pragma once /// ALBUM ENTRY HPP

#include "u_png_color_button.hpp"
#include "c_delete_album.hpp"
#include "c_show_specific_album.hpp"
#include "u_text_box.hpp"
#include "u_entry_with_button.hpp"

class AlbumEntry : public UiElement, private EntryWithButton
{
private:
    SharedPtr<PAlbum> album_ptr_;
    
    PngSprite      del_btn_sprite_;
    ColorButton    col_btn_;
    ColorButton    del_btn_;

    int number_;

    void SetPosition(const std::pair<int,int>& pos) = delete;

    int GetWidth()  const override;
    int GetHeight() const override;

public:
    AlbumEntry(SharedPtr<PAlbum> album_ptr, int number);
    
    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};