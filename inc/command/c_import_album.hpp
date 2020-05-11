#pragma once // C_IMPORT_ALBUM_HPP_

#include "command.hpp"
#include "c_directory_select.hpp"
#include "a_knowledge.hpp"

/**
 * TO DO
*/
class CImportAlbum : public Command
{
private:

public:
    CImportAlbum();

    void Execute() override;
};
