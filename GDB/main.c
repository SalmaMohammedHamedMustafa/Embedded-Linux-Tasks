#include <stdio.h>

void pr ()
{
    for (int i=0 ; i<5;i++)
    {
        printf("hello\n");
    }
}

int main()
{
    printf("hello hello\n");
    pr();
    return 0;
}