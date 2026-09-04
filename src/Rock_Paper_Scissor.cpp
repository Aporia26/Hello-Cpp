//*********** MAKING OF ROCK/PAPER/SCISSOR GAME****************************************************************************
    
#include <iostream>
#include <ctime>
                            //putting our functions
char UserChoice();
char ComputerChoice();
void ShowChoice(char choice);
void chooseWinner(char player, char computer);

int main(){                   //uing our functions
  char player;
  char computer;

  player = UserChoice();
  std::cout <<"Your Choice: ";
  ShowChoice(player);

  computer = ComputerChoice();
  std::cout << "Computer's Choice: ";
  ShowChoice(computer);

  chooseWinner(player,computer);

   
  return 0;
}                            //defining our functions
char UserChoice(){
  char player;
  std::cout << "Welcome to the Rock-Paper-Scissors GAME!";
  std::cout<<  "__________________________________________";
       do{
        std::cout<<"Choose one of the followings\n";
        std::cout<<"'r' for Rock!\n";
        std::cout<<"'p' for Paper!\n";
        std::cout<<"'s' for Scissors!\n";
        std::cin >> player;
       }while(player !='r' && player !='p' && player!='s');
   return player;    
}
char ComputerChoice(){
 srand(time(0));
 int num = rand()% 3 + 1;
 switch(num){
  case 1: return 'r';
  case 2: return 'p';
  case 3: return 's';
 }
return 0;
}
void ShowChoice(char choice){
  switch(choice){
    case 'r': std::cout <<"Rock!\n";
                break;
    case 'p': std::cout <<"Paper!\n";         
                break;
    case 's': std::cout<<"Scissors!\n";
                break;                                    //HOW to decide winner(main stuff)
  }                       
}                                       
void chooseWinner(char player, char computer){
   switch(player){
    case 'r': if(computer == 'r'){
            std::cout <<"It's a TIE! \n";
    }
          else if(computer == 'p'){
           std::cout <<"You LOSE! \n";
          }
          else{
           std::cout <<"You WIN! \n";
          } 
                 break;
     case 'p': if(computer == 'r'){
            std::cout <<"You WIN! \n";
    }
          else if(computer == 'p'){
           std::cout <<"It's a TIE! \n";
          }
          else{
           std::cout <<"You LOSE! \n";
          } 
                 break;
     case 's': if(computer == 'r'){
            std::cout <<"You LOSE! \n";
    }
          else if(computer == 'p'){
           std::cout <<"You WIN! \n";
          }
          else{
           std::cout <<"It's a TIE! \n";
          } 
                 break;                              
   }
}