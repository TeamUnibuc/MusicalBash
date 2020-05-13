#pragma once /// SHOW SPECIFIC ALBUM

#include "command.hpp"
#include "p_album.hpp"
#include "a_knowledge.hpp"

class CShowSpecificAlbum : public Command
{
private:
    SharedPtr<PAlbum> album_;

public:
    CShowSpecificAlbum(SharedPtr<PAlbum> ptr);

    void SetAlbum(SharedPtr<PAlbum> ptr);

    void Execute() override;
};