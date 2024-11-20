#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
LLD of snake and ladder game.
**/
 

class Player {
  
public:
  
  string name;
  int currentPos;
  
  Player() {}
  
  // getter and setter
  Player(string name, int currentPos) : name(name), currentPos(currentPos) {}
  
};

class Dice {
  
  int mn = 1;
  int mx = 6;
  int diff = mx - mn + 1;
  
public:
  
  int diceCount;
  // this will specify how many dices are in the game
  
  Dice() {}
  
  // getter & setter
  Dice(int diceCount) : diceCount(diceCount) {}
  
  int roll() {
    // this will give added output after rolling diceCount number of dices
    
    int sm = 0;
    
    for(int i=0; i<diceCount; i++) {
      
      // random number between [mn, mx]
      sm += (mn + (rand()%diff));
      
    }
    
    return sm;
  }
  
};

class Jump {
  
public:
  
  int startPos;
  int endPos;
  
  
  Jump() {}
  // default constructor to creat Jump jumpObj in Cell
  
  
  // getter & setter
  Jump(int startPos, int endPos) : startPos(startPos), endPos(endPos) {}
  
  
};

class Cell {
  
public:
  
  Jump jumpObj;
  bool hasJump = true;
  
  
  Cell() {} 
  // default constructor to creat <vector<Cell> in Board
  
  // either a cell will contain a jump object or not
  
  Cell(Jump jumpObj) {
    
    this->jumpObj = jumpObj;
    
    // handling the case of a cell not having a jump object
    if(jumpObj.startPos == -1) {
      hasJump = false;
    } 
    
  } 
  
};

class Board {
  
public:
  
  int n;
  vector<Cell> playingBoard;
  
  Board() {}
  
  Board(int n) {
    this->n = n;
    playingBoard.resize(n);
    
    Jump temp(-1,-1);
    
    for(int i=0; i<n; i++) {
      // filling each cell without a jump object
      playingBoard[i] = temp;
    }
    
  }
  
  
};

class Game {
  
public:
  
  Board board;
  Dice dice;
  queue<Player> q;
  
  int n;
  int number_of_dices;
  int number_of_players;
  int number_of_snakes;
  int number_of_ladders;
  
  Game() {}
  
  // getter & setter
  Game(int n, int number_of_dices, int number_of_players, int number_of_snakes, int number_of_ladders) : n(n), number_of_dices(number_of_dices), number_of_players(number_of_players), number_of_snakes(number_of_snakes), number_of_ladders(number_of_ladders) {
    
    initialiseGame();
  }
  
  void initialiseGame() {
    
    board = Board(n);
    dice = Dice(number_of_dices);
      
    cout << "Enter player details :\n";
    for(int i=0; i<number_of_players; i++) {
      string name;
      cin >> name;
      
      Player p(name, 0);
      q.push(p);
      // every player starts at position 0
    }
    
    for(int i=0; i<number_of_snakes; i++) {
      // let us create start and end randomly
      
      int start = 0 + (rand()%n);
      int end = 0 + (rand()%n);
      
      if(start < end) {
        // behaviour of snake
        swap(start, end);
      }
      
      
      
      board.playingBoard[start] = Cell(Jump(start, end));
    }
    
    for(int i=0; i<number_of_ladders; i++) {
      // let us create start and end randomly
      
      int start = 0 + (rand()%n);
      int end = 0 + (rand()%n);
      
      if(start > end) {
        // behaviour of ladder
        swap(start, end);
      }
            
      board.playingBoard[start] = Cell(Jump(start, end));
    }
    
    
  }
  
  void startGame() {
    
    
    Player currentPlayer;
    
    while(true) {
      
      
      currentPlayer = q.front();
      
      cout << "Turn :" << currentPlayer.name << " Position : " << currentPlayer.currentPos << '\n';
      
      int nextPos = currentPlayer.currentPos + dice.roll();
      if(nextPos >= n) {
        break;
      }
      
      // checking if nextPos contains any jump
      if(board.playingBoard[nextPos].hasJump == true) {
        
        nextPos = board.playingBoard[nextPos].jumpObj.endPos;
        
      } 
      currentPlayer.currentPos = nextPos;
      
      
      q.pop();
      q.push(currentPlayer);
    }
    
    
    cout << "Winner is : " << currentPlayer.name << '\n';
  }
  
};

 
 
int main() {
  
  
  Game g(25, 3, 2, 5, 10);
  g.startGame();
  
  
  return 0;
}


