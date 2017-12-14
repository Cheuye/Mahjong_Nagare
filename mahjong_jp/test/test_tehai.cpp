/* Some tests for tehai */

#include "../include/tehai.hpp"
#include <iostream>
#include <random>
using namespace Mahjong_JP;

std::ostream &operator<< (std::ostream& os, const Tehai& th) {
    for (int i = 0; i < 14; i++) {
        os << th.at(i).name() << ":" 
            << static_cast < std::underlying_type< TehaiStatus >::type > (th.status(i))
            << " ";
    }
    return os;
}

Index hai_generator() {
    static std::random_device rd;
    static std::default_random_engine generator(rd());
    static std::uniform_int_distribution < int > index_gen(1, 37);

    return index_gen(generator);
}

int main(int argc, char **argv) {
    std::array < Hai, 13 > th13_1;
    for (int i = 0; i < 13; i++) {
        Index id = hai_generator();
        th13_1[i] = Hai(id);
        std::cout << id << " ";
    }
    std::cout << std::endl;
    Tehai tehai13_1 = Tehai(th13_1);
    std::cout << tehai13_1 << std::endl;
    std::cout << "shuhai: " << tehai13_1.num_shu() << std::endl;
    std::cout << "man: " << tehai13_1.num_m() << std::endl;
    std::cout << "pin: " << tehai13_1.num_p() << std::endl;
    std::cout << "so: " << tehai13_1.num_s() << std::endl;
    std::cout << "chunchan: " << tehai13_1.num_chunchan() << std::endl;

    std::array < Hai, 14 > th14_1;
    for (int i = 0; i < 14; i++) {
        Index id = hai_generator();
        th14_1[i] = Hai(id);
        std::cout << id << " ";
    }
    std::cout << std::endl;
    Tehai tehai14_1 = Tehai(th14_1);
    std::cout << tehai14_1 << std::endl;
    std::cout << "routou: " << tehai14_1.num_routou() << std::endl;
    std::cout << "ji: " << tehai14_1.num_z() << std::endl;
    std::cout << "fon: " << tehai14_1.num_fon() << std::endl;
    std::cout << "sangen: " << tehai14_1.num_sangen() << std::endl;
    std::cout << "yaochu: " << tehai14_1.num_yaochu() << std::endl;
    tehai14_1.change_status(11, TehaiStatus::ANKAN);
    std::cout << tehai14_1 << std::endl;
    return 0; 
}