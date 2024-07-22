#include <iostream>

typedef int ArrType;
/*
finds the maximum of an array of any type
@param the array , the size of the array
@return the maximum of the array
*/
ArrType FindMax (ArrType arr[],int size)
{
    int Max =0;
    for (int i=0; i< size; i++)
    {
        if (arr[i]>Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

int main()
{
    ArrType MyArr[] = {1,2,5,4,3};
    std::cout<<FindMax(MyArr, sizeof(MyArr)/sizeof(MyArr[0]))<<"\n";
    return 0;
}