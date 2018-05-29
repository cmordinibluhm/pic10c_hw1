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
    
    std::ofstream gamelog;
    gamelog.open("gamelog.txt");
    
    srand(time(NULL)); //see random numbers
    
    Player player; //construct a Player with 100 pesos
    Player dealer(900); //construct a dealer with 900 pesos
    
    bool new_round = true; //true as long as the player has money to bet or the dealer hasn't lost 900
    int game_no = 1; //track the number of games/rounds played
    
    while (new_round) { //------------------------------- while loop for round ------------------------------------------//
        
        std::cout << "You have $" << player.get_money() << ". Enter bet: ";
        int bet = 0;
        std::cin >> bet;
        
        Hand player_hand; //construct the player's hand
        
        string player_draws = "y"; //string to act like a boolean to continue or end the players turn
        
        while (player_draws == "y") { //------------------ while loop for player's turn -----------------------------//
            
            std::cout << "Your cards: \n " << player_hand; //display all the players cards
            
            std::cout << "Your total is " << player_hand.get_total() << ". "; //display the player's total
            
            if (player_hand.get_total() >= 7.5) { //if the player has 7.5 or more
                std::cout << "Your turn is over. Let's see how the dealer does." << '\n';
                break; //end players turn
            }
            
            std::cout << "Do you want another card (y/n)? ";
            std::cin >> player_draws; //user enters y or n to indicate if they would like another card

            if (player_draws == "n") { //if the user inputs "n"
                break; //end player's turn
            }
            
            std::cout << "New card: \n \t";
            Card card; //construct a new card
            card.print(); //display the card
            std::cout << "\n";
            player_hand.draw_card(card); //add the card to the player's hand
            
        } //------------------------------------------ end player's turn -----------------------------------------//
    
        
        Hand dealer_hand; //construct the dealer's hand
        
        std::cout << "Dealer's cards: \n" << dealer_hand; //display all the dealer's cards
        
        std::cout << "The Dealer's total is: " << dealer_hand.get_total() << "\n"; //display the dealer's total
        
         while (dealer_hand.get_total() < 5.5) { //------------------------ while loop for dealer's turn ---------------------------//
             
            if (dealer_hand.get_total() < 5.5) { //if the dealer's total is still below 5.5
                std::cout << "\nNew card: \n\t";
                Card card; //construct a new card
                card.print(); //display that card
                dealer_hand.draw_card(card); //add it to the dealer's hand
                std::cout << '\n';
            }
             
             std::cout << "Dealer's cards: \n" << dealer_hand; //displayer all the dealer's cards
             
             std::cout << "The Dealer's total is: " << dealer_hand.get_total() << "\n\n"; //display the dealer's total
        } //------------------------------------------ end dealer's turn -----------------------------------------//
        
        const double dt = dealer_hand.get_total(); //variables to avoid repeated calling of .get_total()
        const double pt = player_hand.get_total();
        
        if (pt > 7.5) { //if the player busts (regardless of whether the dealer busts or not)
            player.lose_bet(bet);
            dealer.win_bet(bet);
            std::cout << "You lose " << bet << ". ";
            
        } else if ((pt <= 7.5) && (dt > 7.5)) { //else if the dealer busts and you don't
            player.win_bet(bet);
            dealer.lose_bet(bet);
            std::cout << "You win " << bet << ". ";

        } else if ((dt < pt) && (pt <= 7.5)) { //else if the player gets closer to 7.5
            player.win_bet(bet);
            dealer.lose_bet(bet);
            std::cout << "You win " << bet << ". ";
            
        } else if ((dt > pt) && (dt <= 7.5)) { //else if the dealer gets closer to 7.5
            player.lose_bet(bet);
            dealer.win_bet(bet);
            std::cout << "You lose " << bet << ". ";
            
        } else { //else neither dealer nor player bust and they have same amount
            std::cout << "It's a tie. ";
        }
     
        if ( player.get_money() <= 0) { //if the player is out of money
            new_round = false; //game ends
            std::cout << "You're out of money.";
            
        } else if (dealer.get_money() <= 0) { //else if the dealer is out of money (has lost 900)
            new_round = false; //game ends
            std::cout << "Congratulations. You beat the casino!";
        }
        
        
        //----------- record the game in gamelog.txt ------------
        gamelog << "------------------------------------------------- \n\n"
                << "Game number: " << game_no << "\t\t" << "Money left: $" << player.get_money() << '\n'
                << "Bet: " << bet << "\n\n"
                << "Your cards: \n"
                << player_hand
                << "Your total: " << player_hand.get_total() << ".\n\n"
                << "Dealer's cards: \n"
                << dealer_hand
                << "Dealer's total is " << dealer_hand.get_total() << ". \n\n";
        
        
        ++game_no;
    } //--------------------------------------------------- end round ---------------------------------------------------//
    gamelog << "------------------------------------------------- \n";
    gamelog.close(); //close the output stream
    
    std::cin.get();
    std::cin.get();
    
    return 0;
}
