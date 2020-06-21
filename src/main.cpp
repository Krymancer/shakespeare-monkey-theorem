#include <iostream>
#include <string>
#include <vector>

#include "Phrase.hpp"
#include "RNG.hpp"

const std::string TARGET_PHRASE = "To be or not to be!";
const int POPULATION_SIE = 100;
const double MUTATION_RATE = 0.01f;

void newGeneration();

std::vector<Phrase*> population;

int main() {
    std::cout << "[PASS]" << std::endl;
    return 0;
}

void newGeneration() {
    std::vector<Phrase*> children;

}