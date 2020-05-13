#pragma once /// UI SONG ALBUM ENTRY HPP

#include "u_entry_with_button.hpp"
#include "p_playlist.hpp"
#include "p_music.hpp"
#include "u_png_sprite.hpp"
#include "u_color_button.hpp"
#include "u_text_box.hpp"

#include "c_add_music_queue.hpp"
#include "c_delete_song_from_playlist.hpp"

class SongPlaylistEntry : public UiElement, private EntryWithButton
{
    SharedPtr<PPlaylist> pl_ptr_;
    SharedPtr<PMusic>    song_ptr_;

    PngSprite     sprite_del_btn_;
    ColorButton   col_btn_;
    ColorButton   del_btn_;

    int number_;

    int GetHeight() const override;
    int GetWidth()  const override;

    void SetPosition(const std::pair<int,int>& pos) = delete;

public:
    SongPlaylistEntry(SharedPtr<PPlaylist> pl_ptr, SharedPtr<PMusic> ms_ptr, int number);

    void Update(int off_x, int off_y) override;

    void Render(sf::RenderWindow& rw, int off_x, int off_y) override;
};