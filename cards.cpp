#include "cards.h"
#include <cstdlib>
#include <iostream>

/* 
You might or might not need these two extra libraries 
#include <iomanip>
#include <algorithm>
*/


//-----------------------------------------------------------------------------//
//                          Card class implementations                         //
//-----------------------------------------------------------------------------//

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; //aces
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; //squire
      case  9: rank = CABALLO; break; //knight
      case 10: rank = REY; break; //king
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
std::string Card::get_spanish_suit() const {
    std::string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
std::string Card::get_spanish_rank() const {
    std::string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}

// Accessor: returns a string with the suit of the card in English
std::string Card::get_english_suit() const {
    std::string suitName;
    switch (suit) {
        case OROS:
            suitName = "golds";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "swords";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English
std::string Card::get_english_rank() const {
    std::string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Squire";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

double Card::get_value() const {
    if (static_cast<int>(rank) + 1 >= 10) {
        return .5;
    } else {
        return static_cast<int>(rank) + 1;
    }
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (const Card& card2) const {
   return rank < card2.rank;
}

void Card::print() const {
    std::cout << std::setw(20) << std::left << this->get_spanish_rank() + " de " + this->get_spanish_suit();
    
    std::cout << "(" << this->get_english_rank() + " of " + this->get_english_suit() + "). \n";
}



//-----------------------------------------------------------------------------//
//                          Hand class implementations                         //
//-----------------------------------------------------------------------------//

Hand::Hand() : vec_of_cards() {
    vec_of_cards.push_back(Card());
}

//non-member
std::ostream& operator<<(std::ostream& out, const Hand& _hand) {
    
    for (size_t i = 0; i != _hand.vec_of_cards.size(); ++i) {
        
        out << '\t';

        out << std::setw(20) << std::left << _hand.vec_of_cards[i].get_spanish_rank() + " de " + _hand.vec_of_cards[i].get_spanish_suit();
        
        out << "(" + _hand.vec_of_cards[i].get_english_rank() + " of " + _hand.vec_of_cards[i].get_english_suit() + "). \n";
    }
    return out;
}

void Hand::draw_card(Card& card) {
    vec_of_cards.push_back(card);
}

double Hand::get_total() const {
    double total = 0;
    
    for (auto i : vec_of_cards) { //range-based for loop thru the vec representing the hand
        total += i.get_value(); //sum the ranks
    }
    return total;
}


//-----------------------------------------------------------------------------//
//                          Player class implementations                       //
//-----------------------------------------------------------------------------//

Player::Player(int m) : money(m) { }

int Player::get_money() const {
    return money;
}

void Player::win_bet(int bet) {
    money += bet;
}

void Player::lose_bet(int bet) {
    money -= bet;
}





