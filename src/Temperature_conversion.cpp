#include <iostream>
#include <cmath> 
#include <ctime>
 int main()
{

//THIS IS TEMPERATURE CONVERSION PROGRAMME***************************

double temp;
char unit;
std::cout << "*********************** TEMPERATURE ****************************************'\n'";

std::cout << "F= FARENHEITE'\n'";
std::cout << "C= CELSIUS'\n'";
std::cout << "k= KELVIN'\n'";
std::cout << " What unit would to like to conevert to? '\n'";
std::cin >> unit;
if(unit == 'F' || unit == 'f'){
         std::cout << "Enter the temperature in 'celsius': "<<'\n';
         std::cin >> temp;
         temp = ((9/5)*temp) + 32;
         std::cout << "Temperature is " << temp << "F"<<'\n';
}
else if(unit == 'C' || unit == 'c'){
           std::cout << "Enter the temperature in 'farenheite': "<<'\n';
         std::cin >> temp;
         temp = (temp - 32)*(5/9);
         std::cout << "Temperature is " << temp << "C"<<'\n';
}
else if(unit == 'k' || unit == 'K'){
           std::cout << "Enter the temperature in 'celsius': "<<'\n';
         std::cin >> temp;
         temp = 273.15 + temp;
         std::cout << "Temperature is " << temp << "K"<<'\n';
}
else{
  std::cout << " Please enter a valid response! ";
}
std::cout << "****************************************************************************'\n'";

return 0;
}