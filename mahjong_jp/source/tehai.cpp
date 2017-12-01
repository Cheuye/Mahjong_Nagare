#include "../include/tehai.hpp"

using namespace Mahjong_JP;
/* private */
void Tehai::update_tehai_types() {
    for (auto &it : tehai_) {
        if (it.first.is_chunchan()) {
            tehai_type_[4] += 1;
            tehai_type_[0] += 1;
            if (it.first.is_m()) {
                tehai_type_[1] += 1;
            } else if (it.first.is_p()) {
                tehai_type_[2] += 1;
            } else {
                tehai_type_[3] += 1;
            }
        } else if (it.first.is_routou()) {
            tehai_type_[5] += 1;
            tehai_type_[0] += 1;
            tehai_type_[9] += 1;
            if (it.first.is_m()) {
                tehai_type_[1] += 1;
            } else if (it.first.is_p()) {
                tehai_type_[2] += 1;
            } else {
                tehai_type_[3] += 1;
            }
        } else {
            tehai_type_[6] += 1;
            tehai_type_[9] += 1;
            if (it.first.is_fon()) {
                tehai_type_[7] += 1;
            } else {
                tehai_type_[8] += 1;
            }
        }
    }
}

void Tehai::update_tehai_types(const Hai& h, Tehai_action a) {
    int modifier = a == TAKE ? 1 : -1;
    if (h.is_chunchan()) {
        tehai_type_[4] += modifier;
        tehai_type_[0] += modifier;
        if (h.is_m()) {
            tehai_type_[1] += modifier;
    } else if (h.is_p()) {
            tehai_type_[2] += modifier;
        } else {
            tehai_type_[3] += modifier;
        }
    } else if (h.is_routou()) {
        tehai_type_[5] += modifier;
        tehai_type_[0] += modifier;
        tehai_type_[9] += modifier;
        if (h.is_m()) {
            tehai_type_[1] += modifier;
        } else if (h.is_p()) {
            tehai_type_[2] += modifier;
        } else {
            tehai_type_[3] += modifier;
        }
    } else {
        tehai_type_[6] += modifier;
        tehai_type_[9] += modifier;
        if (h.is_fon()) {
            tehai_type_[7] += modifier;
        } else {
            tehai_type_[8] += modifier;
        }
    }
}

/* public */

Tehai::Tehai(void) {
    tehai_type_.fill(0);
    for (int i = 0; i < 14; i++) {
        tehai_[i].first = Hai("uk");
        tehai_[i].second = TehaiStatus::JUN;
    }
}

Tehai::Tehai(const std::array < Hai, 13 >& tehai) {
    tehai_type_.fill(0);
    for (int i = 0; i < 13; i++) {
        tehai_[i].first = tehai[i];
        tehai_[i].second = TehaiStatus::JUN;
    }
    tehai_[13].first = Hai("uk");
    tehai_[13].second = TehaiStatus::JUN;
    update_tehai_types();
}

Tehai::Tehai(const std::array < Hai, 14 >& tehai) {
    tehai_type_.fill(0);
    for (int i = 0; i < 14; i++) {
        tehai_[i].first = tehai[i];
        tehai_[i].second = TehaiStatus::JUN;
    }
    update_tehai_types();
}

Hai Tehai::at(int pos) const {
    return tehai_[pos].first;
}

TehaiStatus Tehai::status(int pos) const {
    return tehai_[pos].second;
}

void Tehai::change_status(int pos, TehaiStatus stat) {
    tehai_[pos].second = stat;
}

int Tehai::num_shu() const {
    return tehai_type_[0];
}

int Tehai::num_m() const {
    return tehai_type_[1];
}

int Tehai::num_p() const {
    return tehai_type_[2];
}

int Tehai::num_s() const {
    return tehai_type_[3];
}

int Tehai::num_chunchan() const {
    return tehai_type_[4];
}

int Tehai::num_routou() const {
    return tehai_type_[5];
}

int Tehai::num_z() const {
    return tehai_type_[6];
}

int Tehai::num_fon() const {
    return tehai_type_[7];
}

int Tehai::num_sangen() const {
    return tehai_type_[8];
}

int Tehai::num_yaochu() const {
    return tehai_type_[9];
}
