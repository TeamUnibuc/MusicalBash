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
 * Command that preps Knowledge for pressing the Next button
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
