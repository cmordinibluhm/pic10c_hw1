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
        
        Hand player_hand; //construct the player's hand
        
        string player_draws = "y";
        
        while (player_draws == "y") { //------------------ while loop for player's turn -----------------------------//
            
            std::cout << "Your cards: \n ";
            player_hand.list();
            
            std::cout << "Your total is " << player_hand.get_total() << ". Do you want another card (y/n)? ";
            std::cin >> player_draws;

            if (player_draws == "n") {
                break;
            }
            
            std::cout << "New card: \n \t";
            Card card;
            card.print();
            std::cout << "\n";
            player_hand.draw_card(card);
            
            if (player_hand.get_total() > 7.5) {
                player.lose_bet(bet);
            }
        } //------------------------------------------ end player's turn -----------------------------------------//
    
        
        Hand dealer_hand; //construct the dealer's hand
        
        std::cout << "Dealer's cards: \n";
        dealer_hand.list();
        
        std::cout << "The Dealer's total is: " << dealer_hand.get_total() << "\n";
        
         while (dealer_hand.get_total() < 5.5) { //------------------------ while loop for dealer's turn ---------------------------//
             
            if (dealer_hand.get_total() < 5.5) {
                std::cout << "\nNew card: \n\t";
                Card card;
                card.print();
                dealer_hand.draw_card(card);
                std::cout << '\n';
            }
             
             std::cout << "Dealer's cards: \n";
             dealer_hand.list();
             
             std::cout << "The Dealer's total is: " << dealer_hand.get_total() << "\n\n";
        } //------------------------------------------ end dealer's turn -----------------------------------------//
        
        double dt = dealer_hand.get_total();
        double pt = player_hand.get_total();
        
        if (pt > 7.5) { //if the player busts
            player.lose_bet(bet);
            dealer.win_bet(bet);
            
        } else if ((pt <= 7.5) && (dt > 7.5)) {
            player.win_bet(bet);
            dealer.lose_bet(bet);
            
        } else if ((dt < pt) && (pt <= 7.5)) { //else if the player gets closer to 7.5
            player.win_bet(bet);
            dealer.lose_bet(bet);
            
        } else if ((dt > pt) && (dt <= 7.5)) { //else if the dealer gets closer to 7.5
            player.lose_bet(bet);
            dealer.win_bet(bet);
        }
        
        if ((player.get_money() <= 0) || (dealer.get_money() <= 0)) { new_round = false; }
        
    } //--------------------------------------------------- end round ---------------------------------------------------//
    
    
    std::cin.get();
    std::cin.get();
    
    return 0;
}
