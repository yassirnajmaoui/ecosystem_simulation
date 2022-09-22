#include <list>
#include <random>
#pragma once

class Herb;
class Herbivore;
class Predator;

class World {
public:
    World(int herb_amount, int herbivore_amount, int predator_amount);
    void day();
    void night();
    bool eatHerb();
    bool eatHerbivore();
    void addHerb();
    void addHerbivore();
    void addPredator();
    std::list<Herb> herbs;
    std::list<Herbivore> herbivores;
    std::list<Predator> predators;
    int maxHerbs = 1000;

protected:
    std::default_random_engine generator;
};
