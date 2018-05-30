#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#ifndef CARDS_H
#define CARDS_H

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

    /**
     accessors for Spanish suit and rank
     
     @return string the suit/rank in Spanish
     */
    std::string get_spanish_suit() const;
    std::string get_spanish_rank() const;
    
    /*
     accessors for English suit and rank
     
     @return std::string the suit/rank in English
     */
    std::string get_english_suit() const;
    std::string get_english_rank() const;
    
    /**
     converts Card rank to number
     the possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
     
     @return int the rank of the card
     */
    int get_rank() const;
    
    /**
     get_value function returns the value of the Card
     The possible returns are: 1, 2, 3, 4, 5, 6, 7, 1/2
     
     */
    double get_value() const;
    
    /**
     compare rank of two cards. E.g: Eight<Jack is true.
     assume Ace is always 1
     useful if you want to sort the cards
     
     @param card2 the Card to which to compare the Card called upon
     @return bool true if card2 greatere than the Card called upon
     */
    bool operator<(const Card& card2) const;
    
    /**
     print the card to the console using std::cout
     
     */
    void print() const;
    
private:

    suit_t suit; //suit of the card
    rank_t rank; //rank of the card
    
}; //---------------------------------- end of Card class ------------------------//


/**
 Hand class stores a vector of Card objects
 
 */
class Hand {
    
public:
    
    std::vector<Card> vec_of_cards; //the vector of Cards
    
    /**
     construct a Hand with a randomly generated Card
     
     */
    Hand();
    
    /**
     draw_card function takes a card and adds it to a hand
     
     @param card a Card object by reference to be added to vec_of_cards
     */
    void draw_card(Card& card);
    
    /**
     returns the total rank all the cards in the hand
     
     @return int the sum of the ranks of all the cards in the Hand
     */
    double get_total() const;
    
}; //---------------------------------- end of Hand class ------------------------//

/**
 insertion operator
 
 @param out output stream by reference
 @param _hand Hand object by reference
 */
 std::ostream& operator<<(std::ostream& out, const Hand& _hand);

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
    
    /**
     accessor for the amount of money the Player has left
     
     @return int the amount of money the Player has left
     */
    int get_money() const;
    
    /**
     function to add the bet amount to the Player's money
     use when the Player wins the round
     
     @param bet the amount that the Player bet
     */
    void win_bet(int bet);
    
    /**
     function to subtract the bet amount from the Player's money
     used when the Player loses the round
     
     @param bet the amount that the Player bet
     */
    void lose_bet(int bet);
    
private:
    
    int money; //amount of money the player has left
    
}; //---------------------------------- end of Player class ----------------------//

#endif
