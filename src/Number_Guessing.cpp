 #include <iostream>
#include <cmath> 
#include <ctime>
 int main()
{ 
 
 //******************A NUMBER GUESSING GAME*********************************************************************
   
   int num;
   int guess;
   int tries;
   srand(time(NULL));
    num = (rand()%100) + 1;
   do{
      std::cout << "Guess a number between [1,100]: ";
      std::cin >> guess;
      tries++;
    if(guess>num){
      std::cout<<"Too HIGH!\n";
    }  
    else if(guess<num){
      std::cout<<"Too LOW!\n";
    }
    else{
      std::cout<<"CORRECT! # it took you "<< tries <<'\n';
    }
   }while(guess != num);

   return 0;
}