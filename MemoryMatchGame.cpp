#include <string>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <thread>
#include "unistd.h"
#include "MemoryMatchGame.h"

using namespace std;

//default constructor
MemoryMatchGame::MemoryMatchGame() {
   matches = 0;
   //values for the theme
   animalsTheme[0] = "Animal  ";
   animalsTheme[1] = "Aardvark";
   animalsTheme[2] = "Alpaca  ";
   animalsTheme[3] = "Antelope";
   animalsTheme[4] = "Badger  ";
   animalsTheme[5] = "Bear    ";
   animalsTheme[6] = "Bee     ";
   animalsTheme[7] = "Camel   ";
   animalsTheme[8] = "Cat     ";
   animalsTheme[9] = "Cheetah ";
   animalsTheme[10] = "Deer    ";
   animalsTheme[11] = "Dog     ";
   animalsTheme[12] = "Elephant";
   animalsTheme[13] = "Falcon  ";
   animalsTheme[14] = "Fish    ";
   animalsTheme[15] = "Fox     ";
   animalsTheme[16] = "Goat    ";
   animalsTheme[17] = "Gorilla ";
   animalsTheme[18] = "Heron   ";
   animalsTheme[19] = "Hippo   ";
   animalsTheme[20] = "Horse   ";
   animalsTheme[21] = "Jaguar  ";
   animalsTheme[22] = "Jackal  ";
   animalsTheme[23] = "Kangaroo";
   animalsTheme[24] = "Koala   ";
   animalsTheme[25] = "Lion    ";
   animalsTheme[26] = "Llama   ";
   animalsTheme[27] = "Moose   ";
   animalsTheme[28] = "Mouse   ";
   animalsTheme[29] = "Narwhal ";
   animalsTheme[30] = "Otter   ";
   animalsTheme[31] = "Owl     ";
   animalsTheme[32] = "Panther ";
   animalsTheme[33] = "Pelican ";
   animalsTheme[34] = "Penguin ";
   animalsTheme[35] = "Puma    ";
   animalsTheme[36] = "Quail   ";
   animalsTheme[37] = "Rabbit  ";
   animalsTheme[38] = "Rhino   ";
   animalsTheme[39] = "Shark   ";
   animalsTheme[40] = "Sloth   ";
   animalsTheme[41] = "Snake   ";
   animalsTheme[42] = "Stork   ";
   animalsTheme[43] = "Tiger   ";
   animalsTheme[44] = "Turkey  ";
   animalsTheme[45] = "Turtle  ";
   animalsTheme[46] = "Wallaby ";
   animalsTheme[47] = "Whale   ";
   animalsTheme[48] = "Wolf    ";
   animalsTheme[49] = "Zebra   ";
}

//when start function is called, the game goes through an order of functions
void MemoryMatchGame::start(void) {
   //functions that are called upon during the game
   chooseLevel();
   chooseSpeed();
   setUpGame(level,speed);
   loop();
}

//choose the size of grid using integer difficulty
int MemoryMatchGame::chooseLevel() {
   level = 0;
   cout << "Choose your grid" << endl;
   cout << "1) Easy (4*4 grid)" << endl;
   cout << "2) Medium (6*6 grid)" << endl;
   cout << "3) Hard (8*8 grid)" << endl;
   cin >> level;
   return level;
}

//choose how long cards are displayed
int MemoryMatchGame::chooseSpeed() {
   speed = 0;
   cout << "Speed of play: Please type the corresponding number" << endl;
   cout << "1) Easy (6 sec)" << endl;
   cout << "2) Medium (4 sec)" << endl;
   cout << "3) Hard (2 sec)" << endl;
   cin >> speed;
   return speed;
}

//actual game play - begins with the setting up of board
void MemoryMatchGame::setUpGame(int level, int speed) {
   srand((unsigned)time(NULL));

   if (level > 3)
   {
      chooseLevel();
      
   }

   if (speed > 3)
   {
      chooseSpeed();
      
   }

   
   
   switch (level)
   {
   case 1:
      size = 4;
      terms = 8;
      break;
   case 2:
      size = 6;
      terms = 18;
      break;
   case 3:
      size = 8;
      terms = 32;
      break;
   }

   cout << "Playing with level " << level << endl;

   for (int r=0; r<size; r++){  
            for (int c=0; c<size; c++){  
                cards[r][c] = animalsTheme[0];  
            }  
   }
   for (int i=0; i<terms; i++)
   {
      string animal = animalsTheme[rand()%48 + 1];
      while (1)
      {
         ra = rand() % size;
         ca = rand() % size;
         if ( cards[ra][ca] == animalsTheme[0])
         {
            cards[ra][ca] = animal;
            break;
         }
      }
      while (1)
      {
         rb = rand() % size;
         cb = rand() % size;
         if ( cards[rb][cb] == animalsTheme[0])
         {
            cards[rb][cb] = animal;
            break;
         }
      }
   }
}

void MemoryMatchGame::loop()
{ 
      char comma;

      while (1)
      {
         cout << "Theme: Animals" << endl;
         for (int r = 0; r < size; r++)
         {
            cout << "    " << r+1 << "   ";
         }

         cout << endl;  
         for (int i=0; i<=(size*8+1); i++){  
            cout<<"-";  
         } 
         cout << endl;
         for (int r=0; r< size; r++){  
            cout<<r+1<<" | ";  
            for (int c=0; c<size; c++){  
               cout<< animalsTheme[0];  
            }  
            cout<<endl;  
         }
         while (1)
         {
            cout << "Please insert the first card row and column seperated by a comma. Type '0,0' to exit the game. " << endl;
            cin >> r1 >> comma >> c1; 
            if (r1 == 0)
            {
               return;
            }
            if (status[r1-1][c1-1] == 0)
            {
               break;
            }
         }
         while (1)
         {
            cout << "Please insert the second card row and column seperated by a comma." << endl;
            cin >> r2 >> comma >> c2;
            if (status[r2-1][c2-1] == 0)
            {
               break;
            }
         }
         
         for (int r = 0; r < size; r++)
         {
            cout << "    " << r+1 << "   ";
         }

         cout << endl;  
         for (int i=0; i<=(size*8+1); i++){  
            cout<<"-";  
         } 
         cout<<endl;  
         for (int r=0; r<size; r++){  
            cout<<r+1<<" | ";  
            for (int c=0; c<size; c++){ 
               if ((r+1==r1)&&(c+1==c1))
               {
                  cout << cards[r][c];
               }
               else if ((r+1==r2)&&(c+1==c2))
               {
                  cout << cards[r][c];
               }
               else {
                  cout << animalsTheme[0];
               }
         }  
         cout<<endl;  
      }
      if (cards[r1-1][c1-1]==cards[r2-1][c2-1]){  
          cout << "Match" << endl;
          status[r1-1][c1-1] = 1;
          status[r2-1][c2-1] = 1;
          matches++;
          if (matches == terms)
          {
            
             cout << "You have made all the matches. Game over!" << endl;
             return;
          }
      } 
      else
      {
          cout << "Not A Match!!" << endl;  
      }

      sleep(speed);
      
}  

}

