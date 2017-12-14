#pragma once

#include "tehai.hpp"

namespace Mahjong_JP {
    namespace Util {
        bool is_shuntsu(Mahjong_JP::Hai& h1, Mahjong_JP::Hai& h2, Mahjong_JP::Hai& h3);
        bool is_kotsu(Mahjong_JP::Hai& h1, Mahjong_JP::Hai& h2, Mahjong_JP::Hai& h3);
        bool is_mentsu(Mahjong_JP::Hai& h1, Mahjong_JP::Hai& h2, Mahjong_JP::Hai& h3);
        bool is_toitsu(Mahjong_JP::Hai& h1, Mahjong_JP::Hai& h2);
        bool is_tatsu(Mahjong_JP::Hai& h1, Mahjong_JP::Hai& h2);
    }
}