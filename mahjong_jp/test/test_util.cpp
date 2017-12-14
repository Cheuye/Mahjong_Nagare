/* Some tests for utils */

#include "../include/util.hpp"
#include <iostream>
#include <random>
using namespace Mahjong_JP;

void test_mentsu() {
    /* Shuntsu */
    // 1
    Hai h1 = Hai(12);
    Hai h2 = Hai(13);
    Hai h3 = Hai(14);
    std::cout << "1-true: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "1-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 1+
    h1 = Hai(10);
    h2 = Hai(11);
    h3 = Hai(12);
    std::cout << "1+-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "1+-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 2
    h1 = Hai(19);
    h2 = Hai(20);
    h3 = Hai(21);
    std::cout << "2-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "2-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 3
    h1 = Hai(31);
    h2 = Hai(32);
    h3 = Hai(33);
    std::cout << "3-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "3-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 4
    h1 = Hai(10);
    h2 = Hai(11);
    h3 = Hai(12);
    std::cout << "4-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "4-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 5
    h1 = Hai(5);
    h2 = Hai(6);
    h3 = Hai(7);
    std::cout << "5-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "5-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 6
    h1 = Hai(14);
    h2 = Hai(15);
    h3 = Hai(17);
    std::cout << "6-true: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "6-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 7
    h1 = Hai(25);
    h2 = Hai(27);
    h3 = Hai(28);
    std::cout << "7-true: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "7-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 8
    h1 = Hai(13);
    h2 = Hai(14);
    h3 = Hai(15);
    std::cout << "8-true: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "8-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 9
    h1 = Hai(15);
    h2 = Hai(15);
    h3 = Hai(15);
    std::cout << "9-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "9-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 10
    h1 = Hai(32);
    h2 = Hai(32);
    h3 = Hai(32);
    std::cout << "10-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "10-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 11
    h1 = Hai(2);
    h2 = Hai(2);
    h3 = Hai(2);
    std::cout << "11-false: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "11-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 11+
    h1 = Hai(8);
    h2 = Hai(9);
    h3 = Hai(10);
    std::cout << "11+-true: " << Util::is_shuntsu(h1, h2, h3) << std::endl;
    std::cout << "11+-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    /* Kotsu */
    // 12
    h1 = Hai(13);
    h2 = Hai(13);
    h3 = Hai(13);
    std::cout << "12-true: " << Util::is_kotsu(h1, h2, h3) << std::endl;
    std::cout << "12-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 13
    h1 = Hai(14);
    h2 = Hai(15);
    h3 = Hai(15);
    std::cout << "13-false: " << Util::is_kotsu(h1, h2, h3) << std::endl;
    std::cout << "13-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 14
    h1 = Hai(15);
    h2 = Hai(16);
    h3 = Hai(16);
    std::cout << "14-true: " << Util::is_kotsu(h1, h2, h3) << std::endl;
    std::cout << "14-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 15
    h1 = Hai(14);
    h2 = Hai(14);
    h3 = Hai(15);
    std::cout << "15-false: " << Util::is_kotsu(h1, h2, h3) << std::endl;
    std::cout << "15-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 16
    h1 = Hai(35);
    h2 = Hai(35);
    h3 = Hai(36);
    std::cout << "16-false: " << Util::is_kotsu(h1, h2, h3) << std::endl;
    std::cout << "16-false: " << Util::is_mentsu(h1, h2, h3) << std::endl;

    // 17
    h1 = Hai(35);
    h2 = Hai(35);
    h3 = Hai(35);
    std::cout << "17-true: " << Util::is_kotsu(h1, h2, h3) << std::endl;
    std::cout << "17-true: " << Util::is_mentsu(h1, h2, h3) << std::endl;
}

void test_tatsu_toitsu() {
    // 1
    Hai h1 = Hai(35);
    Hai h2 = Hai(35);
    std::cout << "1-true: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "1-false: " << Util::is_tatsu(h1, h2) << std::endl;

    // 2
    h1 = Hai(34);
    h2 = Hai(35);
    std::cout << "2-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "2-false: " << Util::is_tatsu(h1, h2) << std::endl;

    // 3
    h1 = Hai(9);
    h2 = Hai(10);
    std::cout << "3-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "3-true: " << Util::is_tatsu(h1, h2) << std::endl;

    // 4
    h1 = Hai(20);
    h2 = Hai(21);
    std::cout << "4-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "4-false: " << Util::is_tatsu(h1, h2) << std::endl;

    // 5
    h1 = Hai(25);
    h2 = Hai(26);
    std::cout << "5-true: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "5-false: " << Util::is_tatsu(h1, h2) << std::endl; 

    // 6
    h1 = Hai(24);
    h2 = Hai(26);
    std::cout << "6-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "6-true: " << Util::is_tatsu(h1, h2) << std::endl;

    // 7
    h1 = Hai(23);
    h2 = Hai(26);
    std::cout << "7-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "7-true: " << Util::is_tatsu(h1, h2) << std::endl;   

    // 8
    h1 = Hai(21);
    h2 = Hai(23);
    std::cout << "8-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "8-true: " << Util::is_tatsu(h1, h2) << std::endl;   
    
    // 8
    h1 = Hai(29);
    h2 = Hai(31);
    std::cout << "9-false: " << Util::is_toitsu(h1, h2) << std::endl;
    std::cout << "9-false: " << Util::is_tatsu(h1, h2) << std::endl;   
}

int main(int argc, char **argv) {
    test_mentsu();
    std::cout << "------------------------------" << std::endl;
    test_tatsu_toitsu();
    return 1;
}