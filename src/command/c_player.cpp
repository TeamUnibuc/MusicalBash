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

SliderCommand::SliderCommand()
{ }

SliderCommand::~SliderCommand()
{ }

CPlayerSetVol::CPlayerSetVol()
{ }

void CPlayerSetVol::Execute(double volume)
{
    if (volume < 0. || volume > 100.)
        throw bad_behaviour("Invalid volume: received " + std::to_string(volume));
    Player& ref = *Knowledge::Daddy_Player;

    ref.setVolume(volume);
}

CPlayerSetPlayingOffset::CPlayerSetPlayingOffset()
{ }

void CPlayerSetPlayingOffset::Execute(double value)
{
    if (value < 0. || value > 100.)
        throw bad_behaviour("Invalid percentage: received " + std::to_string(value));
    Player& ref = *Knowledge::Daddy_Player;

    double length = ref.getActiveSongDuration();
    double new_offset = value * length / 100.;
    ref.setActiveSongPlayingOffset(new_offset);
}
