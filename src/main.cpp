#include "Living.hpp"
#include "World.hpp"
#include <iostream>
#include <vector>

int main(int, char**)
{
    World w(700, 55, 1);
    // Better version:
    // Instead of simulating each entity, simulate the model of the ecosystem
    for (int i = 0; i < 100; i++) {
        w.day();
        std::cout << w.herbs.size() << "," << w.herbivores.size() << "," << w.predators.size() << std::endl;
        w.night();
    }
}
