#include <random>
#include <iostream>

int main() {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(1, 9);

    for (int i=0; i<16; ++i)
        std::cout << distr(eng) << "\n";
}
