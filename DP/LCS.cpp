#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int m, n;
vector <char> x, y;

int c[100][100];
char b[100][100];

void getInput()
{
    freopen("file.txt", "r", stdin);
   //cout << "Enter m and n: " << endl;
   cin >> m >> n;

   //cout << "Enter x: ";
   for(int i=0; i<m; i++)
   {
    char temp;
    cin >> temp;
    x.push_back(temp);
   }

//    cout << "Enter y: ";
   for(int i=0; i<n; i++)
   {
    char temp;
    cin >> temp;
    y.push_back(temp);
   }
}

void LCS()
{

    for(int i=0; i<=m; i++)
    {
        c[i][0]= 0;
    }

    for(int j=0; j<=n; j++)
    {
        c[0][j]= 0;
    }

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1]== y[j-1])
            {
                c[i][j]= c[i-1][j-1]+1;
                b[i][j]= 'd';
            }

            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j]= c[i-1][j];
                b[i][j]= 'u';
            }
            else{
                c[i][j]= c[i][j-1];
                b[i][j]= 'l';
            }
        }
    }


}

void printLCS(int i, int j)
{
    if(i==0 || j==0) return;
    if(b[i][j]== 'd')
    {
        printLCS(i-1, j-1);
        cout << x[i-1] << " ";
    }
    else if(b[i][j]== 'u')
        printLCS(i-1, j);
    else printLCS(i, j-1);
}

int main()
{
    getInput();
    LCS();
    cout << "len= " << c[m][n] << endl;
    printLCS(m, n);
    cout << endl;
}