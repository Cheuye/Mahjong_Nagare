#pragma once

#include "hai.hpp"
#include <iostream>
#include <array>
#include <utility>

namespace Mahjong_JP {
    enum class TehaiStatus {JUN, FORO, ANKAN, MINKAN};

    class Tehai {
    private:
        /* 
            tehai_ (a hand) is an ordered array of hai, every hai in tehai is 
            respond to a status_ which indicates whether the hai is in foro or 
            is in a kantsu.

            * furo is part of tehai.
            * order: 
                (1) p < s < m < z;
                (2) furo < ankan < juntehai;
                (3) aka5(p, s, m) < 5(p, s, m).
        */

        /*
            JUN: juntehai, hai that is not in foro.
            FORO:
            ANKAN:
            MINKAN: daiminkan
            
            status_[i] == JUN means tehai[i] is in juntehai.
        */
            
        std::array < std::pair < Mahjong_JP::Hai, TehaiStatus >, 14 > tehai_;
        
        bool tehai_order_less(
            const std::pair < Mahjong_JP::Hai, TehaiStatus >& p1,
            const std::pair < Mahjong_JP::Hai, TehaiStatus >& p2)
            const;

        /*
            0: current number of hais
            1: number of shu
            2: number of manzu
            3: number of pinzu
            4: number of souzu
            5: number of chunchan
            6: number of routou
            7: number of ji
            8: number of fon
            9: number of sangen
            10: number of yaochu
        */
        std::array < int, 10 > tehai_type_;

        enum Tehai_action {TAKE, DROP};
        void update_tehai_types();
        void update_tehai_types(const Mahjong_JP::Hai& h, Tehai_action a);

    public:
        Tehai(void);
        Tehai(const std::array < Mahjong_JP::Hai, 13 >& tehai);
        Tehai(const std::array < Mahjong_JP::Hai, 14 >& tehai);
        // Tehai(array tehai, array stats);

        Mahjong_JP::Hai at(int pos) const;

        TehaiStatus status(int pos) const;
        void change_status(int pos, TehaiStatus stat);

        int num_hais() const;

        int num_shu() const;
        int num_m() const;
        int num_p() const;
        int num_s() const;
        int num_chunchan() const;
        int num_routou() const;

        int num_z() const;
        int num_fon() const;
        int num_sangen() const;

        int num_yaochu() const;

        void sort();
        
        // int find(Mahjong_JP::Hai& hai) const;

        // void take(Mahjong_JP::Hai& hai);

        // void drop(Mahjong_JP::Hai& hai);
    };
}
