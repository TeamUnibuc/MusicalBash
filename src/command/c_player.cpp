#include "c_player.hpp"

CPlayerShuffle::CPlayerShuffle()
{}

void CPlayerShuffle::Execute()
{
    const bool shuffle = Knowledge::Daddy_Player->getSufflingStatus();
    Knowledge::Daddy_Player->setSufflingStatus(1 - shuffle);
}

CPlayerPlayPause::CPlayerPlayPause()
{}

void CPlayerPlayPause::Execute()
{
    const bool isPlaying = (Knowledge::Daddy_Player->getPlayingStatus() == 0);
    if (not isPlaying)
        Knowledge::Daddy_Player->PlayMusic();
    else
        Knowledge::Daddy_Player->PauseMusic();
}


CPlayerNext::CPlayerNext()
{}

void CPlayerNext::Execute()
{
    Knowledge::Daddy_Player->Next();
}

CPlayerBack::CPlayerBack()
{}

void CPlayerBack::Execute()
{
    Knowledge::Daddy_Player->Prev();
}

/**
 * Command that preps Knowledge for pressing the Next button
 */
CPlayerStop::CPlayerStop()
{}

void CPlayerStop::Execute()
{
    Knowledge::Daddy_Player->StopMusic();
}


CPlayerVolDown::CPlayerVolDown()
{}

void CPlayerVolDown::Execute()
{
    Player& ref = *Knowledge::Daddy_Player;
    --ref;
}

CPlayerVolUp::CPlayerVolUp()
{}

void CPlayerVolUp::Execute()
{
    Player& ref = *Knowledge::Daddy_Player;
    ++ref;
}



