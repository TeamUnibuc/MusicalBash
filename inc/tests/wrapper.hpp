#ifndef INC_UNIT_TESTS__
#define INC_UNIT_TESTS__

#include <iostream>
#include <functional>

#include "tests/sound_player_t.hpp"
#include "tests/file_select_t.hpp"
#include "tests/directory_select_t.hpp"

namespace unit_tests
{
    void RunAllTests();
    void RunSpecificTests();
}

#endif