#include "u_entry_with_button.hpp"

using EWB = EntryWithButton;

const int   EWB::kEntryWidth   = 710;
const int   EWB::kButtonWidth  = 100;
const int   EWB::kHeight       = 66;
const int   EWB::kActualHeight = 80;
const int   EWB::kGap          = 30;
const int   EWB::kSpriteOffset = 8;
const float EWB::kHeightRatio  = 0.7;

const std::pair<int, int> EWB::kColBtnPos = {0, kHeight * (1. - kHeightRatio) / 2};
const std::pair<int, int> EWB::kDelBtnPos = {kEntryWidth + kGap, kHeight * (1. - kHeightRatio) / 2};

const std::pair<int, int> EWB::kColBtnSize = {kEntryWidth, kHeight * kHeightRatio};
const std::pair<int, int> EWB::kDelBtnSize = {kHeight * kHeightRatio, kHeight * kHeightRatio};
