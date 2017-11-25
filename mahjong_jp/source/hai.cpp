#include "../include/hai.hpp"

using namespace Mahjong_JP;

const std::unordered_map < Index, std::string > Hai::HAI_NAME = {
    {0, "uk"},
    {1, "1p"}, {2, "2p"}, {3, "3p"}, {4, "4p"}, {5, "5p"}, {6, "6p"}, {7, "7p"}, {8, "8p"}, {9, "9p"},
    {10, "1s"}, {11, "2s"}, {12, "3s"}, {13, "4s"}, {14, "5s"}, {15, "6s"}, {16, "7s"}, {17, "8s"}, {18, "9s"},
    {19, "1m"}, {20, "2m"}, {21, "3m"}, {22, "4m"}, {23, "5m"}, {24, "6m"}, {25, "7m"}, {26, "8m"}, {27, "9m"},
    {28, "1z"}, {29, "2z"}, {30, "3z"}, {31, "4z"},
    {32, "5z"}, {33, "6z"}, {34, "7z"},
    {35, "0p"}, {36, "0s"}, {37, "0m"}
};

const std::unordered_map < std::string, Index > Hai::HAI_ID = {
    {"uk", 0},
    {"1p", 1}, {"2p", 2}, {"3p", 3}, {"4p", 4}, {"5p", 5}, {"6p", 6}, {"7p", 7}, {"8p", 8}, {"9p", 9},
    {"1s", 10}, {"2s", 11}, {"3s", 12}, {"4s", 13}, {"5s", 14}, {"6s", 15}, {"7s", 16}, {"8s", 17}, {"9s", 18},
    {"1m", 19}, {"2m", 20}, {"3m", 21}, {"4m", 22}, {"5m", 23}, {"6m", 24}, {"7m", 25}, {"8m", 26}, {"9m", 27},
    {"1z", 28}, {"2z", 29}, {"3z", 30}, {"4z", 31},
    {"5z", 32}, {"6z", 33}, {"7z", 34},
    {"0p", 35}, {"0s", 36}, {"0m", 37}
};

Index Hai::get_id(std::string name) {
    auto got = Hai::HAI_ID.find(name);
    if (got == Hai::HAI_ID.end()) {
        std::cerr << "Unknown hai name ( " << name << " )" << std::endl;
        return 0;
    } else {
        return got->second;
    }
}

std::string Hai::get_name(Index id) {
    auto got = Hai::HAI_NAME.find(id);
    if (got == Hai::HAI_NAME.end()) {
        std::cerr << "Unknown hai name ( " << id << " )" << std::endl;
        return "uk";
    } else {
        return got->second;
    }
}

Hai::Hai(std::string name) {
    id_ = Hai::get_id(name);
    name_ = Hai::HAI_NAME.at(id_);
}

Hai::Hai(Index id) {
    name_ = Hai::get_name(id);
    id_ = Hai::HAI_ID.at(name_);
}

Index Hai::id() const {
    return id_;
}

std::string Hai::name() const {
    return name_;
}

bool Hai::is_shu() const {
    return (id_ >= 1 && id_ <= 27) || (id_ >= 35 && id_ <= 37); 
}

bool Hai::is_m() const {
    return (id_ >= 19 && id_ <= 27) || id_ == 37;
}

bool Hai::is_s() const {
    return (id_ >= 10 && id_ <= 18) || id_ == 36;
}

bool Hai::is_p() const {
    return (id_ >= 1 && id_ <= 9) || id_ == 35;
}

bool Hai::is_chunchan() const {
    return (id_ > 1 && id_ < 9) || 
        (id_ > 10 && id_ < 18) || 
        (id_ > 19 && id_ < 27) ||
        (id_ >= 35 && id_ <= 37);
}

bool Hai::is_routou() const {
    return (is_shu() && !is_chunchan());
}

bool Hai::is_z() const {
    return (id_ >= 28 && id_ <= 34);
}

bool Hai::is_fon() const {
    return (id_ >= 28 && id_ <= 31);
}

bool Hai::is_sangen() const {
    return (id_ >= 32 && id_ <= 34);
}

bool Hai::is_yaochu() const {
    return (is_routou() || is_z());
}

bool Hai::is_aka() const {
    return id_ >= 35 && id_ <= 37;
}