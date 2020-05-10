#include "c_show_music_queue.hpp"

CShowMusicQueue::CShowMusicQueue()
{}

void CShowMusicQueue::Execute()
{
    Knowledge::curr = Constants::State::W::Queue;
}