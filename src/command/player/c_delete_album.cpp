#include "c_delete_album.hpp"

CDeleteAlbum::CDeleteAlbum(SharedPtr<PAlbum> ptr) : a_ptr(ptr)
{}

void CDeleteAlbum::SetAlbum(SharedPtr<PAlbum> ptr)
{
    a_ptr = ptr;
}

void CDeleteAlbum::Execute()
{
    Logger::Get() << "INFO: Total Albums: " << Knowledge::Daddy_Player->getAlbums().size() << '\n';
    Logger::Get() << "  -  Deleting Album: " << a_ptr->GetName() << '\n';

    Knowledge::Daddy_Player->DeleteAlbum(a_ptr);

    Logger::Get() << "INFO: Left after delete Albums:" << Knowledge::Daddy_Player->getAlbums().size() << '\n';
}