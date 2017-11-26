#pragma once

#include <array>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>

typedef int Index;

namespace Mahjong_JP {
    class Hai {
    private:
        Index id_; // 1 ~ 45
        std::string name_;

        static const std::unordered_map < Index, std::string > HAI_NAME;
        static const std::unordered_map < std::string, Index > HAI_ID;

    public:
        Hai(){};
        Hai(std::string name);
        Hai(Index id);

        Index id() const;
        std::string name() const;

        static Index get_id(std::string name);
        static std::string get_name(Index id);

        bool operator<(const Mahjong_JP::Hai &hai) const;
        bool operator<=(const Mahjong_JP::Hai &hai) const;
        bool operator==(const Mahjong_JP::Hai &hai) const;

        bool is_shu() const;
        bool is_m() const;
        bool is_s() const;
        bool is_p() const;
        bool is_chunchan() const;
        bool is_routou() const;
        bool is_z() const;
        bool is_fon() const;
        bool is_sangen() const;
        bool is_yaochu() const;

        bool is_aka() const;
    };
}