#include<stdio.h>

int L[100], a[100], Lp[100], prev[100], n, len_L;

void getInput()
{
    scanf("%d", &n);
    //a[0]=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void LIS()
{
    L[0]= -99999;
    Lp[0]=-1;
    prev[0]=-1;
    len_L=0;

    for(int i=1; i<=n; i++)
    {
        if(L[len_L] < a[i])
        {
            L[++len_L]= a[i];
            Lp[len_L]= i;
            prev[i]= Lp[len_L-1];
        }
        else{
            int s=0, h= len_L;
            while(s<h)
            {
                int m= (s+h)/2;
                if(L[m] < a[i])
                {
                    s= m+1;
                }
                else
                {
                    h=m;
                }
            }
            L[s]= a[i];
            Lp[s]= i;
            prev[i]= Lp[s-1];
        }
    }
}

void printLIS(int i)
{
 if(i==-1) return;
 printLIS(prev[i]);
 printf("%d ", a[i]);
}

int main()
{
    freopen("LIS.txt", "r", stdin);
    getInput();
    LIS();
    printf("l= %d\n", len_L);

    printLIS(n);
}