#include "../include/hai.hpp"

using namespace Mahjong_JP;

/* private */

const std::unordered_map < Index, std::string > Hai::HAI_NAME = {
    {1, "1m"}, {2, "2m"}, {3, "3m"}, {4, "4m"}, {5, "0m"}, {6, "5m"}, {7, "6m"}, {8, "7m"}, {9, "8m"}, {10, "9m"},
    {11, "1p"}, {12, "2p"}, {13, "3p"}, {14, "4p"}, {15, "0p"}, {16, "5p"}, {17, "6p"}, {18, "7p"}, {19, "8p"}, {20, "9p"},
    {21, "1s"}, {22, "2s"}, {23, "3s"}, {24, "4s"}, {25, "0s"}, {26, "5s"}, {27, "6s"}, {28, "7s"}, {29, "8s"}, {30, "9s"},
    {31, "1z"}, {32, "2z"}, {33, "3z"}, {34, "4z"},
    {35, "5z"}, {36, "6z"}, {37, "7z"},
    {38, "uk"}
};

const std::unordered_map < std::string, Index > Hai::HAI_ID = {
    {"1m", 1}, {"2m", 2}, {"3m", 3}, {"4m", 4}, {"0m", 5}, {"5m", 6}, {"6m", 7}, {"7m", 8}, {"8m", 9}, {"9m", 10},
    {"1p", 11}, {"2p", 12}, {"3p", 13}, {"4p", 14}, {"0p", 15}, {"5p", 16}, {"6p", 17}, {"7p", 18}, {"8p", 19}, {"9p", 20},
    {"1s", 21}, {"2s", 22}, {"3s", 23}, {"4s", 24}, {"0s", 25}, {"5s", 26}, {"6s", 27}, {"7s", 28}, {"8s", 29}, {"9s", 30},
    {"1z", 31}, {"2z", 32}, {"3z", 33}, {"4z", 34},
    {"5z", 35}, {"6z", 36}, {"7z", 37},
    {"uk", 38}
};

/* public */

Index Hai::get_id(std::string name) {
    auto got = HAI_ID.find(name);
    if (got == HAI_ID.end()) {
        std::cerr << "Unknown hai name ( " << name << " )" << std::endl;
        return 38;
    } else {
        return got->second;
    }
}

std::string Hai::get_name(Index id) {
    auto got = HAI_NAME.find(id);
    if (got == HAI_NAME.end()) {
        std::cerr << "Unknown hai name ( " << id << " )" << std::endl;
        return "uk";
    } else {
        return got->second;
    }
}

Hai::Hai(std::string name) {
    id_ = get_id(name);
    name_ = HAI_NAME.at(id_);
}

Hai::Hai(Index id) {
    name_ = get_name(id);
    id_ = HAI_ID.at(name_);
}

Index Hai::id() const {
    return id_;
}

std::string Hai::name() const {
    return name_;
}

bool Hai::operator<(const Hai& h) const {
    return id_ < h.id();
}

bool Hai::operator<=(const Hai& h) const {
    return id_ <= h.id();
}

bool Hai::operator==(const Hai& h) const {
    return id_ == h.id();
}

bool Hai::operator!=(const Hai& h) const {
    return !(id_ == h.id());
}

bool Hai::is_shu() const {
    return (id_ >= 1 && id_ <= 30); 
}

bool Hai::is_m() const {
    return (id_ >= 1 && id_ <= 10);
}

bool Hai::is_s() const {
    return (id_ >= 21 && id_ <= 30);
}

bool Hai::is_p() const {
    return (id_ >= 11 && id_ <= 20);
}

bool Hai::is_chunchan() const {
    return (id_ > 1 && id_ < 10) || 
        (id_ > 11 && id_ < 20) || 
        (id_ > 21 && id_ < 30);
}

bool Hai::is_routou() const {
    return (is_shu() && !is_chunchan());
}

bool Hai::is_z() const {
    return (id_ >= 31 && id_ <= 37);
}

bool Hai::is_fon() const {
    return (id_ >= 31 && id_ <= 34);
}

bool Hai::is_sangen() const {
    return (id_ >= 35 && id_ <= 37);
}

bool Hai::is_yaochu() const {
    return (is_routou() || is_z());
}

bool Hai::is_aka() const {
    return id_ == 5 || id_ == 15 || id_ == 25;
}