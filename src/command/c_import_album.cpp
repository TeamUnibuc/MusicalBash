#include "c_import_album.hpp"

CImportAlbum::CImportAlbum()
{}

void CImportAlbum::Execute()
{
    CDirectorySelect directory_select;
    directory_select.Execute();
    Knowledge::Daddy_Player->CreateAlbum(directory_select.GetResult());
    Logger::Get() << "Album added successfully!!! \n";
}