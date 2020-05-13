#include "c_show_music_queue.hpp"

CShowMusicQueue::CShowMusicQueue()
{}

void CShowMusicQueue::Execute()
{
    Knowledge::State::curr_state = Constants::State::W::Queue;
}