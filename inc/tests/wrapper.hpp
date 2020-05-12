#ifndef INC_UNIT_TESTS__
#define INC_UNIT_TESTS__

#include <iostream>
#include <functional>

#include "tests/sound_player_t.hpp"
#include "tests/file_select_t.hpp"
#include "tests/directory_select_t.hpp"
#include "tests/mp3_file_duration_t.hpp"
#include "player_t.hpp"
#include "t_command_tests.hpp"

#include "a_knowledge.hpp"

namespace unit_tests
{
    void RunAllTests();
    void RunSpecificTests();
}

#endif