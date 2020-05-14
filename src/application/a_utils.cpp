#include "a_utils.hpp"

namespace Utils
{
    bool PointInsideRect(std::pair<int,int> mpoz, int topLeftX, int topLeftY, int szX, int szY)
    {
        auto [x, y] = mpoz;
        // Logger::Get() << "Pt inside? " << x << ' ' << y << " | " << topLeftX << ' ' << topLeftY << " | " << szX << ' ' << szY << '\n';
        if (x < topLeftX || x >= topLeftX + szX)
            return 0;
        if (y < topLeftY || y >= topLeftY + szY)
            return 0;
        return 1;
    }

    std::string IntToMinSecondSecond(int time)
    {
        int mins = time / 60;
        const int ss = time % 60;

        std::string ret;

        if (mins == 0)
            ret = "0";

        while (mins > 0) {
            ret.push_back(char('0' + mins % 10));
            mins /= 10;
        }
        std::reverse(ret.begin(), ret.end());

        ret.push_back(':');
        ret.push_back('0' + ss / 10);
        ret.push_back('0' + ss % 10);

        return ret;
    }

    sf::Color RandomColor()
    {
        srand(time(0));
        return sf::Color(1u * (rand() << 16) + rand());
    }

    std::string ReplaceExtensionWith(std::string name, std::string ext)
    {
        while (not name.empty() && name.back() != '.')
            name.pop_back();
        name += ext;
        return name;
    }

}