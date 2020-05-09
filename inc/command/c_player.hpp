#pragma once /// C_PLAYER_HPP_

#include "command.hpp"

/**
 * Command the SHUFFLE button
 */
class CPlayerShuffle : public Command
{
public:
    CPlayerShuffle();

    void Execute() override;
};

/**
 * Command that preps Knowledge for pressing the Next button
 */
class CPlayerPlay : public Command
{
public:
    CPlayerPlay();

    void Execute() override;
};

/**
 * Command the PLAY button
 */
class CPlayerPause : public Command
{
public:
    CPlayerPause();

    void Execute() override;
};


/**
 * Command that preps Knowledge for pressing the Next button
 */
class CPlayerNext : public Command
{
public:
    CPlayerNext();

    void Execute() override;
};


/**
 * Command that preps Knowledge for pressing the Back button
 */
class CPlayerBack : public Command
{
public:
    CPlayerBack();

    void Execute() override;
};


/**
 * Command that preps Knowledge for pressing the Next button
 */
class CPlayerStop : public Command
{
public:
    CPlayerStop();

    void Execute() override;
};

/**
 * Command that preps Knowledge for pressing the Next button
 */
class CPlayerVolUp : public Command
{
public:
    CPlayerVolUp();

    void Execute() override;
};

/**
 * Command that preps Knowledge for pressing the Next button
 */
class CPlayerVolDown : public Command
{
public:
    CPlayerVolDown();

    void Execute() override;
};
