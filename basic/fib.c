#include<stdio.h>

double fibNo[100];

double fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    double a;
    if(fibNo[n] > 0)
    return fibNo[n];

    else 
    {
        a= fib(n-1) + fib(n-2);
        fibNo[n]= a;
    }

    return a;
}

int main()
{
    int a;
    double b;
    printf("Enter n: ");
    scanf("%d",&a);
    b = fib(a);

    printf("Answer = %lf\n", b);
    return 0;
}