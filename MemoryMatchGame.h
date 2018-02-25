#ifndef MEMORYMATCHGAME_H
#define MEMORYMATCHGAME_H


using namespace std;

class MemoryMatchGame {
private:
protected:
   string animalsTheme[50];
   string cards[8][8];
   int status[8][8];
   int matches;
   int level;
   int speed;
   int size;
   int terms;
   int ra;
   int ca;
   int rb;
   int cb;
   int c1;
   int r1;
   int c2; 
   int r2;
   
public:
   MemoryMatchGame();
   void start();
   int chooseLevel();
   int chooseSpeed();
   void setUpGame(int level, int speed);
   void loop();
};

#endif

