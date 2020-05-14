#include "c_add_music_queue.hpp"

CAddMusicQueue::CAddMusicQueue(SharedPtr<PMusic> mPtr) :
    music_(mPtr)
{}

void CAddMusicQueue::Execute()
{
    if (not music_)
        throw player_runtime_error("Executing command CAddMusicQueue with null PMusic pointer\n");

    Knowledge::Daddy_Player->addMusicToQueue(music_);

    Logger::Get() << "Added song : " << music_->getName() << "  to queue\n";
}

void CAddMusicQueue::SetMusic(SharedPtr<PMusic> ptr)
{
    music_ = ptr;
}