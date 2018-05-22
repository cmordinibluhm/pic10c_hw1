#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

/*
 The values for this type start at 0 and increase by one
 afterwards until they get to SIETE.
 The rank reported by the function Card::get_rank() below is
 the value listed here plus one.
 E.g:
 The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
 The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
 */
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

/**
 Card class represents naipes by storing the suit and the rank (in Spanish and English)
 
 */
class Card {
public:
    // Constructor assigns random rank & suit to card.
    Card();
    
    // Accessors
    string get_spanish_suit() const;
    string get_spanish_rank() const;
    
    /*
     These are the only functions you'll need to code
     for this class. See the implementations of the two
     functions above to get an idea of how to proceed.
     */
    string get_english_suit() const;
    string get_english_rank() const;
    
    // Converts card rank to number.
    // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
    int get_rank() const;
    
    /**
     get_value function returns the value of the Card
     The possible returns are: 1, 2, 3, 4, 5, 6, 7, 1/2
     */
    double get_value() const;
    
    // Compare rank of two cards. E.g: Eight<Jack is true.
    // Assume Ace is always 1.
    // Useful if you want to sort the cards.
    bool operator < (Card card2) const;
    
    void print() const;
    
private:

    suit_t suit; //suit of the card
    rank_t rank; //rank of the card
    
}; //----------------------------------end of Card class------------------------//


/**
 Hand class stores a vector of cards
 
 */
class Hand {
public:
    
    vector<Card> vec_of_cards; // A vector of Cards
    
    /**
     construct a Hand with a random Card
     
     */
    Hand();
    
    void list() const;
    
    void draw_card(Card card);
    
    /**
     returns the total rank all the cards in the hand
     
     @return int the sum of the ranks of all the cards in the Hand
     */
    int get_total() const;
    
    // You decide what functions you'll need...
    
private:
    
    // You decide what fields you'll need...
    
}; //----------------------------------end of Hand class------------------------//


/**
 Player class stores the money that the player has
 
 */
class Player {
public:
    
    /**
     constructor for Player class takes an initial value for the Player's money
     or defaults it to 100
     
     @param m the amount of money the Player begins with (default 100)
     */
    Player(int m = 100);
    
    int get_money() const;
    
    void lose_bet(int bet);
    
    // You decide what functions you'll need...
    
private:
    int money; //amount of money the player has left
    // You decide what extra fields (if any) you'll need...
    
}; //----------------------------------end of Player class----------------------//

#endif
