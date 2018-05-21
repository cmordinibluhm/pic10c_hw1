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
    
    bool new_round = true; //true as long as the player has money to bet or the dealer hasn't lost 900
    
    while (new_round) {
        std::cout << "You have $" << player.get_money() << ". Enter bet: ";
        int bet = 0;
        std::cin >> bet;
        
        Hand hand;
        
        std::cout << "Your cards: \n \t ";
        hand.list();
        
        
        player.lose_bet(bet);
        
        if (player.get_money() <= 0) { new_round = false; }
    }
    
    
    std::cin.get();
    std::cin.get();
    
    return 0;
}
