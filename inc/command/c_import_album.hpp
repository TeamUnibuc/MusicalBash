#pragma once // C_IMPORT_ALBUM_HPP_

#include "command.hpp"

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
