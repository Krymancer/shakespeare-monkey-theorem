#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>

#include "RNG.hpp"

#pragma once

class Phrase {
   public:
    Phrase();
    Phrase(std::string phrase);
    ~Phrase();

    /// if character is inside target phrase then increment fitness by 1
    void setFitness(std::string target);

    /// select the best of both; then randomly select the rest
    void crossOver(std::string parentPhrase, std::vector<int> parentLocked);

    /// Mutate
    void mutate();

    char getRandomCharacter();

   private:
    std::string phrase;
    double fitness;
    std::vector<int> locked;

    int TARGET_SIZE;
    const double MUTATION_RATE = 0.01f;
    random_probability_generator<double> rgen;
};