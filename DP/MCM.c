#include<stdio.h>
#define max 10000000

int cost[100][100];
int s[100][100];

int recMCM(int p[], int i, int j);
int recCall(int p[], int n);
void iterMCM(int p[], int n);
void printMCM(int i, int j);

int main()
{
    int n;
    printf("Enter the number of matrix: ");
    freopen("MCM.txt", "r", stdin);
    scanf("%d", &n);
    int p[n+1];
    printf("Enter the p matrix: ");
    for(int i=0; i<=n; i++)
    {
        scanf("%d", &p[i]);
    }

    iterMCM(p, n);
    int minOp= cost[1][n];
    // int minOp= recCall(p, n);
    printf("Minimum number of operations= %d\n", minOp);
    printMCM(1, n);
    printf("\n");
}

int recCall(int p[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            cost[i][j]= max;
        }
    }

    return recMCM(p, 1, n);
}

int recMCM(int p[], int i, int j)
{
    if(cost[i][j] < max)
    {
        return cost[i][j];
    }
    
    if(i==j) cost[i][j]= 0;
    else{
        int q;
        for(int k=i; k<j; k++)
        {
            q= recMCM(p, i, k) + recMCM(p, k+1, j) + (p[i-1]*p[k]*p[j]);
            if(q< cost[i][j])
            {
                cost[i][j]= q;
                s[i][j]= k;
            }
        }
    }

    return cost[i][j];
}

void printMCM(int i, int j)
{
    if(i==j)
    printf("A%d", i);
    else{
        printf("(");
        printMCM(i, s[i][j]);
        printMCM(s[i][j]+1, j);
        printf(")");
    }
}

void iterMCM(int p[], int n)
{
     for(int i=0; i<=n; i++)
    {
        cost[i][i]= 0;
    }

    for(int l=2; l<=n; l++)
    {
        for(int i=1; i<=n-l+1; i++)
        {
            int j = i+l-1;
            cost[i][j]= max;

            for(int k=i; k<j; k++)
            {
                int q= cost[i][k] + cost[k+1][j]+ (p[i-1]*p[k]*p[j]);
                if(q< cost[i][j])
                {
                cost[i][j]= q;
                s[i][j]= k;
                }
            }

        }
    }

}