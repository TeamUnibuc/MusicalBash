#pragma once /// C_PLAYER_HPP_

#include "command.hpp"

#include "a_knowledge.hpp"

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
 * Command that preps Knowledge for pressing the Play button
 */
class CPlayerPlayPause : public Command
{
public:
    CPlayerPlayPause();

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
 * Command that preps Knowledge for pressing the Stop button
 */
class CPlayerStop : public Command
{
public:
    CPlayerStop();

    void Execute() override;
};

/**
 * Command that preps Knowledge for pressing the VolUp button
 */
class CPlayerVolUp : public Command
{
public:
    CPlayerVolUp();

    void Execute() override;
};

/**
 * Command that preps Knowledge for pressing the VolDown button
 */
class CPlayerVolDown : public Command
{
public:
    CPlayerVolDown();

    void Execute() override;
};

/**
 * Slider commands needing extra argument
 */
class SliderCommand
{
protected:
    SliderCommand();
    
public:
    virtual ~SliderCommand();

    virtual void Execute(double value) = 0;
};

/**
 * Command changing the volume value from the volume slider
 */
class CPlayerSetVol : public SliderCommand
{
public:
    CPlayerSetVol();

    void Execute(double volume) override;
};

/**
 * Command changing the playing offset value from the playing slider
 */
class CPlayerSetPlayingOffset : public SliderCommand
{
public:
    CPlayerSetPlayingOffset();

    void Execute(double value) override;
};

