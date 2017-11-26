#include "../include/hai.hpp"

using namespace Mahjong_JP;

const std::unordered_map < Index, std::string > Hai::HAI_NAME = {
    {0, "uk"},
    {1, "1m"}, {2, "2m"}, {3, "3m"}, {4, "4m"}, {5, "5m"}, {6, "6m"}, {7, "7m"}, {8, "8m"}, {9, "9m"},
    {10, "1p"}, {11, "2p"}, {12, "3p"}, {13, "4p"}, {14, "5p"}, {15, "6p"}, {16, "7p"}, {17, "8p"}, {18, "9p"},
    {19, "1s"}, {20, "2s"}, {21, "3s"}, {22, "4s"}, {23, "5s"}, {24, "6s"}, {25, "7s"}, {26, "8s"}, {27, "9s"},
    {28, "1z"}, {29, "2z"}, {30, "3z"}, {31, "4z"},
    {32, "5z"}, {33, "6z"}, {34, "7z"},
    {35, "0p"}, {36, "0s"}, {37, "0m"}
};

const std::unordered_map < std::string, Index > Hai::HAI_ID = {
    {"uk", 0},
    {"1m", 1}, {"2m", 2}, {"3m", 3}, {"4m", 4}, {"5m", 5}, {"6m", 6}, {"7m", 7}, {"8m", 8}, {"9m", 9},
    {"1p", 10}, {"2p", 11}, {"3p", 12}, {"4p", 13}, {"5p", 14}, {"6p", 15}, {"7p", 16}, {"8p", 17}, {"9p", 18},
    {"1s", 19}, {"2s", 20}, {"3s", 21}, {"4s", 22}, {"5s", 23}, {"6s", 24}, {"7s", 25}, {"8s", 26}, {"9s", 27},
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

bool Hai::operator<(const Hai &hai) const {
    return id_ < hai.id();
}

bool Hai::operator<=(const Hai &hai) const {
    return id_ <= hai.id();
}

bool Hai::operator==(const Hai &hai) const {
    return id_ == hai.id();
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