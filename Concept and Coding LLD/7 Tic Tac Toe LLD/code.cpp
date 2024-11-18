#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Tic Tac Toe LLD
**/

//......................PlayingPiece.........................

class PlayingPiece {
  
public:
  
  char value;
  // for classic tic-tac-toe values : {X,O}
  // can also extend it if required
  
  PlayingPiece() {} // this default constructor is needed to define vector<vector<PlayingPiece>> board
  
  PlayingPiece(char value) {
    this->value = value;
  }
  
};

class PlayingPieceX : public PlayingPiece{
  
public:
  
  PlayingPieceX() : PlayingPiece('X') {}
  // passing the parameter of parent class when object of this class is made
};

class PlayingPieceO : public PlayingPiece{
  
public:
  
  PlayingPieceO() : PlayingPiece('O') {}
  // passing the parameter of parent class when object of this class is made
};


class PlayingPieceEmpty : public PlayingPiece {
  
public:
  
  PlayingPieceEmpty() : PlayingPiece('_') {}
  
};

//.....................Board...................................

class Board {
public:
  
  int n;
  vector<vector<PlayingPiece>> board; // you cannot define size here because n is not undefined
  // board has PlayingPiece
  
  PlayingPieceEmpty emp;
  // initially putting empty PlayingPiece in board to avoid NULL value 
  
  Board() {} // for defining Board board in TicTacToe class
  
  Board(int n) {
    this->n = n;
    
    board = vector<vector<PlayingPiece>>(n, vector<PlayingPiece>(n, emp));
    // you can only define size inside constructor because outside of constructor will be executed first, and there n would have not been defined
  }
  
  
  
  // function for performing a move
  int cellsFilled = 0;
  
  
  bool isValidMove(int i, int j, PlayingPiece p) {
    
    if(i < 0 or i>=n or j<0 or j>n) {
      return false;
    }
    
    if(board[i][j].value != '_') {
      return false;
    }
    
    
    board[i][j] = p;
    cellsFilled++;
    // if valid then assigning that PlayingPiece to that cell
    return true;
    
  }
  
  void printBoard() {
    
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cout << board[i][j].value << "|";
      }
      cout << '\n';
    }
    
  }
  
  string doesGameEnd() {
    
    // game ends for 3 reasons : X wins, O wins, All places filled
    
    // row wise checking
    for(int i=0; i<n; i++) {
      int cntX = 0, cntO = 0;
      for(int j=0; j<n; j++) {
        if(board[i][j].value == 'X') {
          cntX++;
        } else if(board[i][j].value == 'O'){
          cntO++;
        }
      }
      
      if(cntX == n) {
        return "X";
      }
      if(cntO == n) {
        return "O";
      }
    }
    
    // column wise checking
    for(int j=0; j<n; j++) {
      int cntX = 0, cntO = 0;
      for(int i=0; i<n; i++) {
        if(board[i][j].value == 'X') {
          cntX++;
        } else if(board[i][j].value == 'O'){
          cntO++;
        }
      }
      
      if(cntX == n) {
        return "X";
      }
      if(cntO == n) {
        return "O";
      }
    }
    
    
    // diagonal checking
    int i=0, j=0;
    int cntX = 0, cntO = 0;
    while(i < n) {
      if(board[i][j].value == 'X') {
          cntX++;
      } else if(board[i][j].value == 'O'){
          cntO++;
      }
      i++;
      j++;
    }
    
    if(cntX == n) {
      return "X";
    }
    if(cntO == n) {
      return "O";
    }
    
    i=0;
    j=n-1;
    cntX = 0;
    cntO = 0;
    while(i < n) {
      if(board[i][j].value == 'X') {
          cntX++;
      } else if(board[i][j].value == 'O'){
          cntO++;
      }
      i++;
      j--;
    }
    
    if(cntX == n) {
      return "X";
    }
    if(cntO == n) {
      return "O";
    }
    
    
    if(cellsFilled == n*n) {
      return "Tie";
    }
    
    return "Continue";
  }
  
  
  
  
  
};


//.............................Player..............................

class Player {
  
public:
  
  string name;
  char value;
  
  PlayingPiece playing_piece;
  // because Player and Playing pieces follows has-a relationship
  // hence getting playingPiece for player using constructor injection
  
  Player() {} // for defining Player in TicTacToe class
  
  Player(string name, char value) {
    this->name = name;
    this->value = value;
    
    if(value == 'X') {
      PlayingPieceX temp;
      playing_piece = temp;
    } else {
      PlayingPieceO temp;
      playing_piece = temp;
    }
    // same reason ye bhi andar hi define karna hoga
    
  }
  
  char getValue() {
    return value;
  }
  
  void setValue(char d) {
    // change the value of piece for this player
    
    if(d == 'X') {
      PlayingPieceX temp;
      playing_piece = temp;
    } else {
      PlayingPieceO temp;
      playing_piece = temp;
    }
  }
  
  
};



//.....................TicTacToe Game.......................

class TicTacToe {
  
public:
  
  int numPlayers;
  int n;
  
  
  Board board;
  deque<Player> dq;
  // TicTacToe has a board
  // TicTacToe has players
  // using deque so that turn of players can be managed easily using popfront and pushback
  
  
  void startGame() {
    Player current;
    bool flag = true;
    
    while(flag == true) {
      
      board.printBoard();
      
      
      current = dq.front();
      cout << "Play your move : " << current.name << '\n';
      
      int row, col;
      cin >> row >> col;
      
      if(board.isValidMove(row, col, current.playing_piece) == false) {
        cout << "Invalid Move\n";
      } else {
        
        string state = board.doesGameEnd();
        if(state == "X") {
          cout << "Rajveer wins\n";
          flag = false;
        } else if(state == "O") {
          cout << "Sushmita wins\n";
          flag = false;
        } else if(state == "Tie") {
          cout << "Tie\n";
          flag = false;
        }
        
        dq.pop_front();
        dq.push_back(current);
        
      }
      
    }
    
  }
  
  TicTacToe(int n, int numPlayers) {
    
    this->n = n;
    this->numPlayers = numPlayers;
    
    // making board
    Board temp(n);
    board = temp;
    
    // making players
    Player one("Rajveer", 'X');
    Player two("Sushmita", 'O');
    
    dq.push_back(one);
    dq.push_back(two);
    
    startGame();
    
  }
  
  
};


 
int main() {
  
  
  TicTacToe game(3, 2);
  
  return 0;
}


