#ifndef DECK__HPP
#define DECK__HPP

#include <string>
#include "Card.hpp"
class Deck {

    private:
        Card* cards;
        int size;

    public:

        Deck(); // constructor
        ~Deck(); // destructor

        void create_new_deck();
        void shuffle_deck();
        void print_deck();

};

#endif