#include "../include/hai.hpp"
#include <iostream>
using namespace Mahjong_JP;

std::ostream &operator<< (std::ostream& os, const Hai& h) {
    os << h.id() << "\t" << h.name();
    return os;
}

int main(int argc, char **agrv) {
    Hai h1 = Hai(35);
    std::cout << h1 << std::endl;
    std::cout << "is_aka: " << h1.is_aka() << std::endl;
    std::cout << "is_z: " << h1.is_z() << std::endl;
    std::cout << "is_shu: " << h1.is_shu() << std::endl;
    std::cout << "is_p: " << h1.is_p() << std::endl;
    std::cout << "is_m: " << h1.is_m() << std::endl;
    std::cout << "is_chunchan: " << h1.is_chunchan() << std::endl;
    
    Hai h2 = Hai("ssss");
    std::cout << h2 << std::endl;
    std::cout << "is_s: " << h2.is_s() << std::endl;

    Hai h3 = Hai("5z");
    std::cout << h3 << std::endl;
    std::cout << "is_routou: " << h3.is_routou() << std::endl;
    std::cout << "is_yaochu: " << h3.is_yaochu() << std::endl;
    std::cout << "is_sangen: " << h3.is_sangen() << std::endl;
    std::cout << "is_fon: " << h3.is_fon() << std::endl;
    return 1;
}