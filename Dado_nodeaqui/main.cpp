#include <iostream>
#include <time.h> // For the time that determines the value of the dice
#include <vector> // For the board
#include <cctype> // To capitalize letters
using namespace std;

class Game {
private:
vector<string> board_type; // Create vector for the type of tyles

void board (){
  // Add elements to the "board_type" vector
  for (int i = 1; i <= 30; ++i) {
    if (i == 4) {
      board_type.push_back("L");
    }
    else if (i == 7) {
      board_type.push_back("L");
    }
    else if(i == 13) {
      board_type.push_back("L");
    }
    else if (i == 17) {
      board_type.push_back("S");
    }
    else if (i == 22) {
      board_type.push_back("S");
    }
    else if (i == 28) {
      board_type.push_back("S");
    }
    else {
      board_type.push_back("N");
    }
  }
}

public:
int dice_value;

Game() {
    board();
}

// Dice method
int dice () { 
  return rand() % 6 + 1; 
}

// Method to get the value of the new tile according to the new player's position
int get_tile_value(int p, int d){
  p = p + d; // Move the position according to the dice's value
  cout << board_type[p - 1]; // Shows the type of tile

  // According to the type of tile, the position's player will move 
  if (board_type[p - 1] == "S") {
      p = p - 3; // If the tile is a snake, move the position back 3 tiles
  } 
  else if (board_type[p - 1] == "L") {
      p = p + 3; // If the tile is a ladder, move the position forward 3 tiles
  }
  if (p > 30) {
    p = 30; // If the position is greater than 30, the position will be set to 30
    // In order to respect the rules of the game
    cout << board_type[p - 1];
  }
  return p;
}

// Method to start the game by calculating and printing specific values
int start(int player, int pos, int t){
  dice_value = dice(); // Get the value of the dice by calling the method "dice"

  // Print the turn, the player, its current position, and the dice's value
  cout << t << " " << player << " " << pos << " " << dice_value << " ";

  // Get the new position by calling the method "get_tile_value"
  pos = get_tile_value(pos, dice_value);

  // Print the new position
  cout <<  " "  << pos << endl;
  
  // Return the new position 
  return pos;
}
};

// Main method
int main() {
  // Important variables
  int turn = 1;
  string answer;
  int player1_pos = 1;
  int player2_pos = 1;

  // Determine the seed of the random number generator based on the time
  srand(time(0));

  // Objects from class game
  Game player1;
  Game player2;

  cout << "**** Snakes and Ladders game ****" << endl;

  // Logic of the game
  while (turn < 11) {
      cout << "\nPress C to continue next turn, or E to end the game: ";
      cin >> answer;
      answer[0] = toupper(answer[0]); // Capitalize the answer

      // If the answer is "C", the game will continue
      if (answer == "C"){
        player1_pos = player1.start(1, player1_pos, turn); // Obtain the new position of player 1
        // If player 1 reaches the end of the board, the game ends
        if (player1_pos >= 30) {
          cout << "\nGAME OVER" << endl;
          cout << "\n" << player1_pos << " Player 1 is the winner!" << endl;
          break;
        }
        
        player2_pos = player2.start(2, player2_pos, turn); // Obtain the new position of player 2
        // If player 2 reaches the end of the board, the game ends
        if (player2_pos >= 30) {
            cout << "\nGAME OVER" << endl;
          cout << "\n" << player2_pos << " Player 2 is the winner!" << endl;
            break;
        }
        // If the game continues, the turn is increased by 1
        turn = turn + 1;
      }

      // If the answer is "E", the game ends
      else if (answer == "E"){
        cout << "\nThanks for playing!!!" << endl;
        break;
      }

      // If the answer is not "C" or "E", this message will appear
      else {
        cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
      }
    }

  // The game ends, if the turn reaches more than 10 turns
  if (turn > 10){
    cout << "\nGAME OVER" << endl;
    cout << "The maximum number of turns has been reached." << endl;
  }
  return 0;
}