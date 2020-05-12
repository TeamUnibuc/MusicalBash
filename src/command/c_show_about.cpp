#include "c_show_about.hpp"

CShowAbout::CShowAbout()
{}

void CShowAbout::Execute()
{
    std::string about = "MusicalBash Copyright 2020\\n";
    about += "Creators: Felix, Costel and Teo";
    system(("zenity --info --text=\"" + about + "\" --no-wrap &").c_str());
}