#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


int main(){
    
    Player player; //default construct a Player with 100 pesos
    Player dealer(900); //construct a dealer with 900 pesos
    
    bool new_round = true; //true as long as the player has money to bet or the dealer hasn't lost 900
    
    while (new_round) { //------------------------------- while loop for round ------------------------------------------//
        
        std::cout << "You have $" << player.get_money() << ". Enter bet: ";
        int bet = 0;
        std::cin >> bet;
        
        Hand player_hand;
        
        string new_card = "y";
        
        while (new_card == "y") { //------------------ while loop for player's turn -----------------------------//
            
            std::cout << "Your cards: \n ";
            player_hand.list();
            
            std::cout << "Your total is " << player_hand.get_total() << ". Do you want another card (y/n)?";
            std::cin >> new_card;

            if (new_card == "n") {
                break;
            }
            
            Card card;
            
            player_hand.draw_card(card);
            
            std::cout << "New card: \n \t";
            card.print();
            
            if (player_hand.get_total() > 7.5) {
                player.lose_bet(bet);
            }
        } //------------------------------------------ end player's turn -----------------------------------------//
    
        
        bool dealer_draws = true;
        
        while (dealer_draws) { //------------------ while loop for dealer's turn ---------------------------//
            
            
            
            
            dealer_draws = false;
        
        } //------------------------------------------ end dealer's turn -----------------------------------------//
        
        
        
        if (player.get_money() <= 0) { new_round = false; }
        
    } //--------------------------------------------------- end round ---------------------------------------------------//
    
    
    std::cin.get();
    std::cin.get();
    
    return 0;
}
