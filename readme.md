# siete y media assignment

## tabla de contenido
[add in all headings in nested structure with internal links to the different parts of the file]

### EL JUEGO
#### OBJETIVO
llegar mas cerco a siete y media que el repartidor para ganar dinero

#### REGLAS

- el juego se termina cuando el jugador ha perdido todo su dinero o cuando el repartidor ha perdido 900 pesos

#### VALORES DE LOS NAIPES
- Los naipes con numeros tiene el valor du sus numeros
- Las sotas, los caballos y los reyes tiene valor de medio punto



### TO DO
#### write program to play siete y media against the player
- keep count of the players money (starts at 100 pesos)
- keep track of the players bet to deduct or add from total money
- input validation so that the user can't bet more than they have
- 3 classes: player, card, and hand
- cards.h and cards.cpp and siete-y-medio.cpp

#### keep a log of the rounds played (thus must play multiple rounds)
- important information about every round should be recorded in gamelog.txt

#### submission

### IDEAS
- use Qt para los graficos? No, that time should be allocated to working on my final project
- include the history of the card game at the beginning of the program
- table of contents for this readme file with internal links to the different sections
- escribir en espanol lo mas posible

### QUESTIONS I HAVE ABOUT THE ASSIGNMENT
- how do I make a gamelog.txt to store important information? I have never done this kind of thing before.

### WHAT I'M GRADED ON
- at least 20 commit messages. These should be descriptive and concise
- at least a master and experimental branch
- at least 1 merge that is non-fast-forward
- other: do something extra (ie conflict resolution, 3-way merging, creating .gitignore files)
    - I will do a .gitignore for sure
- have only txt files unless there is a really good reason, in which case you have to explain it in readme.md


### PROJECT JOURNAL

Journal begins at the time of the fourth commit.

#### May 8, 2018
Today I worked on the assignment for the first time in quite a while. I modified readme.md a bit and copied the code Professor Salazar provided for us for the files cards.h, cards.cpp, and siete-y-medio.cpp.

#### May 20, 2018
Today I started adding my own formatting to cards.h and cards.cpp as well as implementing some of their constructors and member functions.

#### May 21, 2018
Worked on making the main routine in siete-y-medio.cpp match the output from Prof. Salazar's sample runs. Added the functions Player::lose_bet, Player::win_bet, Player::get_money,
Hand::get_total, Hand::draw_card, Hand::list, Card::print, Card::get_value. Attempting to preserve encapsulation and const correctness by using proper accessors. 

#### May 22, 2018
In the morning, worked on the main routine, specifically started the control flow for the dealer's turn. Tried a do-while loop to ensure that after one card is drawn, another is drawn unless
the dealer's total is already more than 5.5, but moved back to a while loop and just put some code before it for the initial display of the dealer's first card. Added in if else statements 
to the end of the round to determine who won the round. As of now it works except in the case where both the dealer and the player bust.

