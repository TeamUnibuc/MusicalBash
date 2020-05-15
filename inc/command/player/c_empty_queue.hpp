#pragma once /// COMMAND EMPTY QUEUE

#include "command.hpp"

#include "a_knowledge.hpp"

class CEmptyQueue : public Command
{
public:
    CEmptyQueue();

    void Execute() override;
};