// created by Molesz at 2022/03/03 10:12.
//
// DE-IK - 2022 - Prog1

#include <iostream>

int main()
{

    auto a = [](int a)
    {
        std::cout << "Hello c++ lambda" << std::endl;
        return a * a;
    };





    auto sum = [](double A, double B){
        return (A+B);
    };
    auto add = sum;
    std::cout << add(2,3)<< std::endl;

    auto add2 = [](double A, double B) -> double {return A+B;};
    std::cout << add2(4,5)<< std::endl;

    double pi = 3.1416;

    auto f = [&pi](){
        pi += 
        std::cout << "[+] Pi: " << pi++ << std::endl;
    };
    f();
    std::cout << "[+] Pi: " << pi << std::endl;


    return 1;
}

