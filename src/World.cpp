#include "World.hpp"
#include "Living.hpp"
#include <random>

World::World(int herb_amount, int herbivore_amount, int predator_amount)
{
    herbs = std::list<Herb>(herb_amount, this);
    herbivores = std::list<Herbivore>(herbivore_amount, this);
    predators = std::list<Predator>(predator_amount, this);
}

void World::day()
{
    for (auto herb_it = herbs.begin(); herb_it != herbs.end(); herb_it++) {
        herb_it->day();
    }
    for (auto herbivore_it = herbivores.begin(); herbivore_it != herbivores.end(); herbivore_it++) {
        herbivore_it->day();
    }
    for (auto predators_it = predators.begin(); predators_it != predators.end(); predators_it++) {
        predators_it->day();
    }
}
void World::night()
{
    for (auto herb_it = herbs.begin(); herb_it != herbs.end(); herb_it++) {
        if (herb_it->getHp() <= 0) {
            herb_it = herbs.erase(herb_it);
        }
    }
    for (auto herbivore_it = herbivores.begin(); herbivore_it != herbivores.end(); herbivore_it++) {
        if (herbivore_it->getHp() <= 0) {
            herbivore_it = herbivores.erase(herbivore_it);
        }
    }
    for (auto predator_it = predators.begin(); predator_it != predators.end(); predator_it++) {
        if (predator_it->getHp() <= 0) {
            predator_it = predators.erase(predator_it);
        }
    }
}

void World::addHerb()
{
    herbs.push_back(Herb(this));
}
void World::addHerbivore()
{
    herbivores.push_back(Herbivore(this));
}
void World::addPredator()
{
    predators.push_back(Predator(this));
}
bool World::eatHerb()
{
    if (herbs.size() == 0)
        return false;
    std::uniform_int_distribution<int> distribution(0, herbs.size() - 1);
    int rand_idx = distribution(generator);
    std::list<Herb>::iterator herb_it = herbs.begin();
    std::advance(herb_it, rand_idx);
    herbs.erase(herb_it);
    return true;
}
bool World::eatHerbivore()
{
    if (herbivores.size() == 0) {
        return false;
    }
    std::uniform_int_distribution<int> distribution(0, herbivores.size() - 1);
    int rand_idx = distribution(generator);
    std::list<Herbivore>::iterator herbivore_it = herbivores.begin();
    std::advance(herbivore_it, rand_idx);
    herbivores.erase(herbivore_it);
    return true;
}
