#include <iostream>
#include <cmath> 
#include <ctime>
 int main()
{

//**********************THIS THE PROJECT OF PYTHAGORAS CALCULATOR*******************************************

double A;
double B;
double C;

std::cout << "enter value for side A: " << '\n';
std::cin >> A;

std::cout << "enter value for side B: " << '\n';
std::cin >> B;

C = sqrt( pow(A,2) + pow(B,2));
 std::cout << " the value of hypotenuse is " << C;

 return 0;
}