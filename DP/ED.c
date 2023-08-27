#include<stdio.h>

int m, n;
char x[100], y[100];
int c[100][100];
char b[100][100];

void getInput()
{
    //freopen("file.txt", "r", stdin);
   //cout << "Enter m and n: " << endl;
   scanf("%d %d", &m, &n);
   
   for(int i=1; i<=m; i++)
   {
        scanf("%c", &x[i]);
   }

   for(int i=1; i<=n; i++)
   {
        scanf("%c", &y[i]);
   }
}

void ED()
{
    int delete, substitute, insert;
    for(int i=0; i<=m; i++)
    {
        c[i][0]= i;
    }

    for(int j=0; j<=n; j++)
    {
        c[0][j]= j;
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i]== y[j])
            {
                c[i][j]= c[i-1][j-1];
                b[i][j]= 'n';
            }
            else{
                substitute= c[i-1][j-1];
                delete= c[i-1][j];
                insert= c[i][j-1];

                if(substitute <= delete && substitute <= insert)
                {
                    c[i][j]= substitute+1;
                    b[i][j]= 's';
                }
                else if(delete < substitute && delete <= insert)
                {
                    c[i][j]= delete+1;
                    b[i][j]= 'd';
                }
                else
                {
                    c[i][j]= insert +1;
                    b[i][j]= 'i';
                }
            }
        }
    }


}

void printops(int i, int j)
{
    if(i==0 || j==0) return;
    if(b[i][j]== 's')
    {
        printops(i-1, j-1);
    }
    else if(b[i][j]== 'd')
    {
        printops(i-1, j);

    }
    else 
    {
        
    }
}

int main()
{
    getInput();
    ED();
    printf("len = %d\n", c[m][n]);
   
}