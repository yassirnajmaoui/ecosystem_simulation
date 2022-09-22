#include "World.hpp"
#include <iostream>
#pragma once

class Living {
public:
    Living(World* w)
        : world(w)
    {
        hp = 100;
        age = 0;
    }
    virtual void day() = 0;
    inline int getHp() const { return this->hp; }
    inline int getAge() const { return this->age; }

protected:
    World* world;
    int hp;
    int age; // number of days
    int maxAge; // Life expectancy constant

    // Reproduction constants
    float reproductionProbability;

    std::default_random_engine generator;
};

class Herb : public Living {
public:
    Herb(World* w)
        : Living(w)
    {
        maxAge = 80;
        reproductionProbability = 0.05;
    }
    void day()
    {
        age++;
        if (age > 365) {
            hp = 0; // Dies of old age
            return;
        }
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double rand_repro = distribution(generator);
        if (rand_repro < reproductionProbability && world->herbs.size() < world->maxHerbs) {
            // Reproduce
            world->addHerb();
        }
    }
};

class Herbivore : public Living {
public:
    Herbivore(World* w)
        : Living(w)
    {
        maxAge = 120;
        reproductionProbability = 0.02;
    }
    void day()
    {
        age++;
        if (age > maxAge) {
            hp = 0; // Dies of old age
            return;
        }
        if (!world->eatHerb()) {
            hp -= 25;
            if (hp <= 0)
                return;
        }
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double rand_repro = distribution(generator);
        if (rand_repro < reproductionProbability) {
            // Reproduce
            world->addHerbivore();
        }
    }
};

class Predator : public Living {
public:
    Predator(World* w)
        : Living(w)
    {
        maxAge = 160;
        reproductionProbability = 0.02;
    }
    void day()
    {
        age++;
        if (age > maxAge) {
            hp = 0; // Dies of old age
            return;
        }
        if (!world->eatHerbivore()) {
            hp -= 25;
            if (hp <= 0)
                return;
        }
        std::uniform_real_distribution<double> distribution(0, 1);
        double rand_repro = distribution(generator);
        if (rand_repro < reproductionProbability) {
            // Reproduce
            world->addPredator();
        }
    }
};
