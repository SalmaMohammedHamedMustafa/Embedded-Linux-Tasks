#include <iostream>

int FindMax (int num1,int num2,int num3)
{
    if (num1>num2&&num1>num3)
    {
        return num1;
    }
    else if (num2>num3) 
    {
        return num2;
    }
    else
    {
        return num3;
        
    }
}

int main ()
{
    int num1;
    int num2;
    int num3;
    std::cout<<"enter the first number: ";
    std::cin>>num1;
    std::cout<<"enter the second number: ";
    std::cin>>num2;
    std::cout<<"enter the third number: ";
    std::cin>>num3;
    std::cout<<"the maximum is: "<<FindMax(num1,num2, num3)<<"\n";
    return 0;
}