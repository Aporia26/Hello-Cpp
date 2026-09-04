#include <iostream>
#include <iomanip>

  void ShowBalance(double balance);
  double deposit();
  double withdraw(double balance);

int main(){

//************************************MAKING A BANKING PROGRAMME PRACTICE*****************************************

  double balance = 9986.67;
  int choice = 0;
  do{
std::cout << "_________________________________ \n";
std::cout << " Enter Your Choice: \n";
std::cout << "|_________________________________| \n";
std::cout << "1) Show Balance \n";
std::cout << "2) Deposit money \n";
std::cout << "3) Withdraw money \n";
std::cout << "4) Exit \n";
       std::cin >>choice;

       std::cin.clear();
       fflush(stdin);

  switch(choice){
    case 1: ShowBalance(balance);
      break;
    case 2: balance=balance + deposit();      //or balance += deposit
             ShowBalance(balance);// to see balance after deposit...
     break;
    case 3: balance=balance - withdraw(balance);  //or balance -= withdraw()
             ShowBalance(balance);
     break;
    case 4: std::cout << "Thanks for visiting!";
     break;
    default: std::cout << "Please Enter a Valid Choice! ";
             
  }
}while( choice != 4);
  return 0;
}


void ShowBalance(double balance){
 std::cout << "Your Current Balance is: $"<< std::setprecision(2) << std::fixed << balance <<'\n';
}
  double deposit(){
    double amount;
    std::cout<<"Enter the amount to be deposited: ";
    std::cin >>amount;
    if(amount>0){
return amount;
}
else{
  std::cout <<"That's not a valid amount!\n";
  return 0;
}
  }
  double withdraw(double balance){
    double amount;
    std::cout<<"Enter the amount to be withdrawn: ";
    std::cin >> amount;
    if(amount > balance){
       std::cout<<"You don't have enough funds! You will be in a Dept! ";
return 0;
}
else if(amount < 0){
  std::cout<<"That's not a valid amount!\n";
   return 0;
  }
  else{
  return amount;
}
  }                        //---IMP DEBUGING---
   //if while trying to run a code an error saying, permission denied id returned 1 exit status, type Stop-Process -Name "helloworld" -Force into the terminal window.
