#include "c_player.hpp"

CPlayerShuffle::CPlayerShuffle()
{}

void CPlayerShuffle::Execute()
{
    Logger::Get() << "Shuffle Button not implemented ! \n";
}

CPlayerPlay::CPlayerPlay()
{}

void CPlayerPlay::Execute()
{
    Logger::Get() << "Play Button not implemented ! \n";
}


CPlayerNext::CPlayerNext()
{}

void CPlayerNext::Execute()
{
    Logger::Get() << "Next Button not implemented ! \n";
}

CPlayerBack::CPlayerBack()
{}

void CPlayerBack::Execute()
{
    Logger::Get() << "Back Button not implemented ! \n";
}


CPlayerPause::CPlayerPause()
{}

void CPlayerPause::Execute()
{
    Logger::Get() << "Pause Button not implemented ! \n";
}

/**
 * Command that preps Knowledge for pressing the Next button
 */
CPlayerStop::CPlayerStop()
{}

void CPlayerStop::Execute()
{
    Logger::Get() << "Stop Button not implemented ! \n";
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



