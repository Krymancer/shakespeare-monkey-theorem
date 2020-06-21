#include <iostream>
#include <random>

#pragma once

template <class Ty = double, class = std::enable_if_t<std::is_floating_point<Ty>::value> >
class random_probability_generator {
   public:
    // default constructor uses single random_device for seeding
    random_probability_generator() : mt_eng{std::random_device{}()}, prob_dist(0.0, 1.0) {}
    // ... other constructors with custom seeds if necessary
    Ty next() { return prob_dist(mt_eng); }
    // ... other methods if necessary
   private:
    std::mt19937 mt_eng;
    std::uniform_real_distribution<Ty> prob_dist;
};