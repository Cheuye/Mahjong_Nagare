#include "../include/util.hpp"

using namespace Mahjong_JP;

/* 
    Function 
    <s_shuntsu> 
    <is_kotsu> 
    <is_menzu> 
    <is_toitsu> ?
    <is_tatsu> 
    works only if h1, h1 (and h3) are in order
*/

bool Util::is_shuntsu(Hai& h1, Hai& h2, Hai& h3) {
    if (h1.is_shu() && (h1.id() - 1) % 10 <= 7
        && h1 != h2 && h1 != h3) {
        if (h1.is_aka()) {
            return h1.id() + 1 + h2.id() + h3.id() == 3 * h2.id();
        } else if (h2.is_aka()) {
            return h1.id() + h2.id() + h3.id() - 1 == 3 * h2.id();
        } else {
            return h1.id() + h2.id() + h3.id() == 3 * h2.id();
        }
    }

    return false;
}

bool Util::is_kotsu(Hai& h1, Hai& h2, Hai& h3) {
    // The number of akas depends on the rule.
    int aka_modifier1 = h1.is_aka() ? 1 : 0;
    int aka_modifier2 = h2.is_aka() ? 1 : 0;
    int aka_modifier3 = h3.is_aka() ? 1 : 0;

    return (h1.id() + aka_modifier1 == h2.id() + aka_modifier2)
        && (h2.id() + aka_modifier3 == h3.id() + aka_modifier3);
}

bool Util::is_mentsu(Hai& h1, Hai& h2, Hai& h3) {
    return (is_kotsu(h1, h2, h3) || is_shuntsu(h1, h2, h3));
}

bool Util::is_toitsu(Hai& h1, Hai& h2) {
    int aka_modifier1 = h1.is_aka() ? 1 : 0;
    int aka_modifier2 = h2.is_aka() ? 1 : 0;

    return (h1.id() + aka_modifier1 == h2.id() + aka_modifier2);
}

bool Util::is_tatsu(Hai& h1, Hai& h2) {
    if (h1.is_shu()) {
        if ((h1.id() - 1) % 10 <= 7) {
            int aka_modifier1 = (h1.id() - 1) % 10 <= 5 ? 1 : 0;
            int diff = h2.id() - (h1.id() + aka_modifier1);
            return (diff <= 2 && diff >= 1);
        } else if ((h1.id() - 1) % 10 == 8) {
            return h1.id() + 1 == h2.id();
        }
    }

    return false;
}