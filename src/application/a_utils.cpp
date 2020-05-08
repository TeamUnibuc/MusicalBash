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
}