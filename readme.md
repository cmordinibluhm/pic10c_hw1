# siete y media assignment

## tabla de contenido

- [El juego](#el-juego)
--- [Objetivo](#objetivo)
--- [Reglas](#reglas)
--- [Valores de los Naipes](#valores-de-los-naipes)
- [To Do](#to-do)
- [Extra Ideas](#extra-ideas)
- [Questions](#questions-about-the-assignment)
- [Grading](#grading)
- [Rubric](#rubric)
- [Project Journal](#project-journal)
--- [Project Reflection](#project-reflection)
--- [Concepts from Class](#concepts-from-class)
--- [Resources](#some-webpages-i-used)

### el juego
#### objetivo
- llegar mas cerco a siete y media que el repartidor para ganar dinero

#### reglas

- el juego se termina cuando el jugador ha perdido todo su dinero o cuando el repartidor ha perdido 900 pesos

#### valores de los naipes
- Los naipes con numeros tiene el valor du sus numeros
- Las sotas, los caballos y los reyes tiene valor de medio punto

### el proyecto
#### write program to play siete y media against the player
- keep count of the players money (starts at 100 pesos)
- keep track of the players bet to deduct or add from total money
- input validation so that the user can't bet more than they have
- 3 classes: player, card, and hand
- cards.h and cards.cpp and siete-y-medio.cpp

#### keep a log of the rounds played (thus must play multiple rounds)
- important information about every round should be recorded in gamelog.txt

#### submit
- uploaded my_repo.txt file with address of the GitHub repository associated with this repo

### Extra Ideas
- use Qt para los graficos? No, that time should be allocated to working on my final project
- include the history of the card game at the beginning of the program?
- table of contents for this readme file with internal links to the different sections? (Or more generally use this file as markdown practice?)
- escribir en espanol lo mas posible

### Questions about the assignment
- how do I make a gamelog.txt to store important information? I have never done this kind of thing before. (DONE)

### Grading
- project journal (CHECK)
- at least 20 commit messages. These should be descriptive and concise (CHECK)
- at least a master and experimental branch (CHECK)
- at least 1 merge that is non-fast-forward (CHECK)
- other: do something extra (ie conflict resolution, 3-way merging, creating .gitignore files) (CHECK)
     - My .gitignore makes a.out and gamelog.txt untracked. a.out is regenerated every time the program is compiled, so it doesn't need to be saved. Similarly, gamelog.txt is rewritten every time
        that the program is run.
    - When I performed my non-fastforward merge conflicts did occur and I had to resolve them.
    - Learned and got more practice with markdown.
- have only txt files unless there is a really good reason, in which case you have to explain it in readme.md (CHECK)

#### Rubric

Points will be assigned based on the following categories:

| **Category** | **Description** | **Points** |
|:-----|:----------------------------------------------------------|:---:|
| `readme.md` | Description of the project including documentation and/or test cases. See [this document][readme-example] for an example of a `readme.md` file. | 4 |
| Commits | You should work in increments and document your work. Try to be descriptive but concise when writing commit messages. For this project you should have at least 20 commit messages. | 4 |
| Branching | You are free to create as many branches as you see fit, but at the very minimum there should be an `experimental` branch where you test features before merging them into your `master` branch. | 4 |
| Merging | At some point in your development history you should merge two branches (_e.g._ `master` and `experimental`). Make sure **at least one of these merges is a non-fast-forward one**. | 4 |
| Other | This is left open for you, topics you might want to research are: _conflict resolutions_, _three-way merging_, creating `gitignore` files, etc. | 2 |
| Binary vs text | Version control software excels in keeping track on contents stored in text files. If your repository contains binary files (_e.g._ `.exe`, `.dll`, `.bin`, etc) there should be a very compelling reason for you to keep track of them. If this is the case you should document this reason in the `readme.md` file; otherwise you should `git rm` these files as soon as you become aware of their existence. | 2 |

### Project Journal

Journal begins at the time of the fourth commit. I did my best to remember to record my progress in the journal. Most of the work was indeed concentrated around May 21-22, as the journal reflects.

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

The cards were not random each time I ran the program so I looked up how to seed the random numbers with srand(time(NULL)).
Added messages to the end of a round based on who one. And message based on the end of the whole game based on whether the dealer or the player ran out of money.
The only problem is that when the player busts and then the dealer busts as well, the game is ended completely, even if the bet was less than the player had left.
It looks like it's taking twice the bet amount.
RESOLVED. There was an extra if statement within the player's turn that deducted the bet immediately, only to have it deducted again at the end of the round.

Reading over the assignment rubric again, I realize that maybe I am supposed to be doing most of my development in an experimental branch before I merge it into master?
I could use more practice merging so I will try that out.

#### May 29, 2018
Today I am actually starting new features in the experimental branch before merging them into the master branch once they work.
Added condition in main routine to stop the player from being able to draw once they have reached or passed 7.5.
Added documentation to main routine.
Made a couple variables const in main routine.
At this point the program works perfectly, and all I need to do is figure out how to save information to the game_log.txt file.
UPDATE: Successfully added an output file stream, pushed some information to it, and checked that it did in fact appear in gamelog.txt. I have hardly worked with file streams before this,
so this is good practice. Easier than I thought.

I had previously been using the Hand::list() to display the player's and dealer's cards. This simply used std::cout to print to the console. This became a problem when I needed to list the cards
in gamelog.txt instead of to the console. As I should have from the beginning, I got rid of the Hand::list() function and instead wrote a more gereric nonmember overloaded operator<<.
Program works and so does writing to gamelog.txt!

Fixed .gitignore to ingnore gamelog.txt while still tracking my_repo.txt

Added <iomanip> library and used it to make sure the English rank and suit of cards were aligned. Main routine and file stream formatting are all fine tuned.
Everything seems to work perfectly, all I need now are some finishing touches.

#### May 30, 2018
Today I put finishing touches on readme.md and the source files. I previously had virtual destructors for each class but since I didn't use inheritance or have any non-RAII members, I realized I didn't have to
provide destructors at all.

#### Project Reflection
This assignment was enjoyable and informative. I became much more familiar with using git from the command line and have come to enjoy it. I even have started using the command line to edit folders and files for other classes.
Next time I use git I will be sure to have an experimental branch from the git go and make sure my master branch always works. I didn't understand the importance of doing that until the end of this assignment.
I was exposed to the iomanip library for the first time, and spent quite a while figuring out how the std::setw(int) and std::left/std::right manipulators worked.
Finally, I got to practice using ofstreams to write to a text file which I hadn't done before. It was surprisingly simple and I'm looking forward to using that on subsequent projects.

#### Concepts I Used from Class
##### Version Control
I used git in the terminal for version control. I initialized a repo, staged files, committed, amended, pushed, branched, merged, and more.

##### STL Containers
I wrapped a std::vector for the Hand class. I also used std::vector's random access capabilities with operator[ ], pre-increment operator, and its size() member function to use a size_t variable to approximate the functions of an iterator.

##### Memory Management
All of my class members such as int and std::vector come RAII ready, and I did not use inheritance, so I did not need to include virtual destructors, which I originally thought I had to do.

##### Templates
I chose not to use templates since this program is small and specific and doesn't need to be made more generic.

##### Markdown
I learned some markdown for this readme.md file. Aside from headings and bullets I learned how to make reference links to other places in the document for my table of contents.

##### Good Habits
I initialized all class members in constructor initializer lists.
I checked for const correctness for variables, functions, and function parameters.

#### Some Webpages I Used
https://stackoverflow.com/questions/9069061/what-is-the-difference-between-git-merge-and-git-merge-no-ff
https://stackoverflow.com/questions/2485963/c-alignment-when-printing-cout
https://stackoverflow.com/questions/11451535/gitignore-is-not-working
https://en.wikipedia.org/wiki/Input/output_(C%2B%2B)#Input/output_streams
http://www.cplusplus.com/forum/beginner/4442/
https://cboard.cprogramming.com/c-programming/135750-scoreboard-saved-txt-file.html
http://nvie.com/posts/a-successful-git-branching-model/
https://www.cloudways.com/blog/manage-branches-and-resolve-conflicts-git/
https://en.wikipedia.org/wiki/Spanish_playing_cards#Description
https://stackoverflow.com/questions/5765645/should-you-commit-gitignore-into-the-git-repos
https://softwareengineering.stackexchange.com/questions/342650/should-i-merge-all-commits-from-an-experimental-branch-or-only-the-valid-one
https://stackoverflow.com/questions/36583502/how-to-force-a-linebreak
https://www.markdowntutorial.com/
https://chrome.google.com/webstore/detail/markdown-preview-plus/febilkbfcbhebfnokafefeacimjdckgl/related


