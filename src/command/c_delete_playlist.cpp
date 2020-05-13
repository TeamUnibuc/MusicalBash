#include "c_delete_playlist.hpp"

CDeletePlaylist::CDeletePlaylist(SharedPtr<PPlaylist> ptr) : pl_ptr(ptr)
{}

void CDeletePlaylist::SetPlaylist(SharedPtr<PPlaylist> ptr)
{
    pl_ptr = ptr;
}

void CDeletePlaylist::Execute()
{
    Logger::Get() << "INFO-COMMAND: Deleting playlist: " << pl_ptr->GetName() << '\n'; 

    if (not pl_ptr)
        throw null_pointer("Trying to execute Command: DeletePlaylist with Null Pointer");

    Knowledge::Daddy_Player->DeletePlaylist(pl_ptr);
}