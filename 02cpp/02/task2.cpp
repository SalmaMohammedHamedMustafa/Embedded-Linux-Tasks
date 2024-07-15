#include <iostream>

typedef int ArrType;
/*
searchs for an element
@param the array , the size of the array, the wanted element
@return the index o the first occurance of the wanted element
*/
ArrType Find (ArrType arr[],int size, int element)
{
    int i =0;
    for (i=0; i< size; i++)
    {
        if (arr[i]==element)
        {
            break;
        }
    }
    return i;
}

int main()
{
    ArrType MyArr[] = {1,2,5,4,3};
    std::cout<<Find(MyArr, sizeof(MyArr)/sizeof(MyArr[0]),5)<<"\n";
    return 0;
}