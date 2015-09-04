#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    printf("Please enter the size from 1 to 23: ");
    
    int n = GetInt();
    
    while(n<0 || n>23)
    {
        printf("Please enter the size from 1 to 23: ");
        n = GetInt();
    }
    
    int i,j,k,m,p;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n-i);j++)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("#");
        }

        printf("  ");

        for(m=1;m<=i;m++)
        {
            printf("#");   
        }
        for(p=1;p<=(n-i);p++)
        {
            printf(" ");
        }
        
        printf("\n");
    }

    return 0;
    
}
