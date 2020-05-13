#pragma once /// COMMAND DELETE ALBUM HPP

#include "command.hpp"
#include "p_album.hpp"
#include "a_knowledge.hpp"

class CDeleteAlbum : public Command
{
private:
    SharedPtr<PAlbum> a_ptr;

public:
    CDeleteAlbum(SharedPtr<PAlbum> ptr = nullptr);

    void SetAlbum(SharedPtr<PAlbum> ptr);

    void Execute() override;
};