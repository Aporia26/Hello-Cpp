
// *********************************QUADRATIC EQUATION SOLVER*********************************************
#include <iostream>
#include <cmath>

    int main(){

      int a, b, c;
      
        std::cout << "Enter three coefficients in order a,b,c: \n";
        std::cout <<"(To have a quadratic eqn as, ax^2 + bx + c)\n";

        std::cin >> a >> b >> c;
        std::cout << "Your quadratic is " << a <<"x^2 + "<< b <<"x + "<< c << '\n';
           
            double root1 = (- b + sqrt(b*b - 4*a*c))/(2*a);
            double root2 = (- b - sqrt(b*b - 4*a*c))/(2*a);
            int D = b*b - 4*a*c;        

      if(a != 0){  

        if(D>0){
            std::cout << "The Roots are real \n";
            std::cout << "The roots are: \n";
            std::cout << root1 << " and "<< root2;
            }
        else if (D<0){
            std::cout << "The Roots are Imaginary!";
         }
        else if(D == 0){
            std::cout << "The Roots are Equal\n";
            std::cout << "The roots are: \n";
            std::cout << root1;
        } 
        }
       
     else{
              std::cout << "Quadratic dosen't exists!!";
       }
        return 0;
    }


