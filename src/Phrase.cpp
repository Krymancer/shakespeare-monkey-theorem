#include "Phrase.hpp"

Phrase::Phrase(std::string phrase) {
    this->phrase = phrase;
    this->fitness = 0.0f;
    this->TARGET_SIZE = phrase.size();
}

void Phrase::setFitness(std::string target) {
    this->fitness = 0;

    for (int i = 0; i < TARGET_SIZE; i++) {
        if (target[i] == this->phrase[i]) {
            this->fitness++;

            // locked not contain i
            if (std::find(this->locked.begin(), this->locked.end(), i) == this->locked.end()) {
                this->locked.push_back(i);
            }
        }
    }
}

void Phrase::crossOver(std::string parentPrase, std::vector<int> parentLocked) {
    std::string phrase = "";

    for (int i = 0; i < TARGET_SIZE; i++) {
        //locked contains i
        if (std::find(this->locked.begin(), this->locked.end(), i) != this->locked.end()) {
            phrase += this->phrase[i];
            continue;
        } else if (std::find(parentLocked.begin(), parentLocked.end(), i) != parentLocked.end()) {
            phrase += parentPrase[i];
            continue;
        }

        phrase += this->rgen.next() > 0.5f ? this->phrase[i] : parentPrase[i];
    }
}

void Phrase::mutate() {
    for (int i = 0; i < TARGET_SIZE; i++) {
        if (this->rgen.next() < MUTATION_RATE) {
            int chosenIndex = floor(this->rgen.next() * (TARGET_SIZE - 1));

            // locked not contais chosenIndex
            if (std::find(this->locked.begin(), this->locked.end(), chosenIndex) == this->locked.end()) {
                this->phrase[chosenIndex] = this->getRandomCharacter();
            }
        }
    }
}

char Phrase::getRandomCharacter() {
    std::string possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789!;";
    int random_index = floor(this->rgen.next() * (possible.size() - 1));
    return possible[random_index];
}