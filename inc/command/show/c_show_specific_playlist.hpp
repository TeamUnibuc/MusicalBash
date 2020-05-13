#pragma once /// SHOW SPECIFIC PLAYLIST HPP

#include "command.hpp"
#include "a_knowledge.hpp"

class CShowSpecificPlaylist : public Command
{
private:
    SharedPtr<PPlaylist> playlist_;

public:
    CShowSpecificPlaylist(SharedPtr<PPlaylist> ptr = nullptr);

    void SetPlaylist(SharedPtr<PPlaylist> ptr);

    void Execute() override;
};