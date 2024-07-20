#include <iostream>

int main()
{
    int num ;
    std::cout<<"Enter the number: ";
    std::cin>>num;
    auto square = [num]{return num*num;};
    std::cout<<"the square of the number is "<<square()<<"\n";
    return 0;
}