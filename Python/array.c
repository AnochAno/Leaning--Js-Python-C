#include <stdio.h>

int main()
{
//Initialize an array with 10 integers and add all the numbers together and print the sum
    int n,arr[10],sum=0;

    printf("Enter 10 elements:");
    for(n=0;n<10;++n)
        scanf("%d",&arr[n]);

    for(n=0;n<10;++n)
        sum=sum+arr[n];
    printf("Sum of numbers is:%d",sum);

    return 0;
}
