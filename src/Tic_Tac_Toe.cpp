#include <iostream>
#include <cmath> 
#include <ctime>

//***************************** TIC TAC TOE GAME ****************************************************************

void drawboard(char *spaces);
void playermove(char *spaces, char player);
void computermove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);


int main(){

  char spaces[9] = {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' ',};
  char player = 'X';
  char computer = 'O';
  bool running = true;

  drawboard(spaces);        //already array when passed into a funtions decays to pointer
  
  while(running){

    playermove(spaces, player);
    drawboard(spaces);
    if(checkWinner(spaces, player, computer)){
      running = false;
      break;

    }
    else if(checkTie(spaces)){
      running = false;
      break;
    }

    computermove(spaces, computer);
    drawboard(spaces);
     if(checkWinner(spaces, player, computer)){
      running = false;
      break;
    }
    else if(checkTie(spaces)){
      running = false;
      break;
    }

  }
    std::cout << "Thanks For Playing!\n";

return 0;
}


void drawboard(char *spaces){
  std::cout << '\n';
  std::cout << "     |     |     \n";
  std::cout << " "<< spaces[0]<<"   | "<<spaces[1]<<"   |  "<<spaces[2]<<"  \n";
  std::cout << " ____|_____|____\n";

   std::cout << "     |     |     \n";
  std::cout << " "<< spaces[3]<<"   | "<<spaces[4]<<"   |  "<<spaces[5]<<"  \n";
  std::cout << " ____|_____|____\n";

   std::cout << "     |     |     \n";
  std::cout << " "<< spaces[6]<<"   | "<<spaces[7]<<"   |  "<<spaces[8]<<"  \n";
    std::cout << '\n';

}
void playermove(char *spaces, char player){
  int number;
  std::cout << "Enter a spot to place your marker (1-9): ";
  std::cin >> number;
  number--;
  do{
  if(spaces[number] == ' '){
    spaces[number] = player;
    break;
  }
}while(!number>0 || !number<8);
  

}
void computermove(char *spaces, char computer){
  int number;
  srand(time(0));
  while (true)
  {
    number = rand() % 9;
    if(spaces[number] == ' '){
      spaces[number] = computer;
      break;
    }
  }
  

}
bool checkWinner(char *spaces, char player, char computer){
  if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
    spaces[0] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
    spaces[3] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
    spaces[6] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
    spaces[0] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
    spaces[1] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
    spaces[2] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
    spaces[0] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
    spaces[2] == player ? std::cout << "YOU WON!!!\n" : std::cout << "YOU LOSE!!!\n"; //ternary operator

  }
  else{
    return false;
  }
return true;
}
bool checkTie(char *spaces){
  for(int i=0; i<9; i++){
    if(spaces[i] == ' '){
      return false;
    }

  }
  std::cout << "IT'S A TIE!!!\n";
  return true;
}