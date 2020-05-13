#include "c_show_specific_album.hpp"

CShowSpecificAlbum::CShowSpecificAlbum(SharedPtr<PAlbum> ptr) : album_(ptr)
{}

void CShowSpecificAlbum::SetAlbum(SharedPtr<PAlbum> ptr)
{
    album_ = ptr;
}

void CShowSpecificAlbum::Execute()
{
    if (not album_)
        throw null_pointer("Running Show Specific Album Command with NullPointer");
    
    Logger::Get() << " Updated Knowledge with Show ViewAlbum   and album name: " << album_->GetName() << '\n';

    Knowledge::State::curr_state = Constants::State::W::ViewAlbum;

    Knowledge::State::data.curr_album = album_;

    Logger::Get() << " Knowledge album: " << Knowledge::State::data.curr_album->GetName() << '\n';
}