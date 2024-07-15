#include <iostream>

typedef int ArrType;
/*
deletes an element
@param the array , the size of the array, the wanted element
*/
void DeleteElement (ArrType arr[],int size, int element)
{
    int i =0;
    bool found = false;
    for (i=0; i< size; i++)
    {
        if (arr[i]==element)
        {
            found = true;
            break;
        }
    }
    if (found==false)
    {
        std::cout<<"the element does not exist\n";
    }
    else
    {
        for (int j =i ;j<size-1;j++)
        {
            arr[j]=arr[j+1];
        }
    }
    
}

int main()
{
    ArrType MyArr[] = {1,2,5,4,3};
    int size =sizeof(MyArr)/sizeof(MyArr[0]);
    DeleteElement(MyArr,size,5);
    for (int i=0;i<size-1;i++)
    {
        std::cout<<MyArr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}