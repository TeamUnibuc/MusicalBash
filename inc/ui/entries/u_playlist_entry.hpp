#pragma once /// UI PLAYLIST ENTRY HPP

#include "u_element.hpp"
#include "p_playlist.hpp"
#include "u_png_sprite.hpp"
#include "u_color_button.hpp"
#include "u_entry_with_button.hpp"
#include "c_show_specific_playlist.hpp"
#include "c_delete_playlist.hpp"
#include "u_text_box.hpp"

class PlaylistEntry : public UiElement, protected EntryWithButton
{
private:
    SharedPtr<PPlaylist> pl_ptr_;

    PngSprite     sprite_del_btn_;
    ColorButton   col_btn_;
    ColorButton   del_btn_;

    int number_;

    int GetHeight() const override;
    int GetWidth()  const override;

    void SetPosition(const std::pair<int,int>& pos) = delete;

public:
    PlaylistEntry(SharedPtr<PPlaylist> pl_ptr, int number);

    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};