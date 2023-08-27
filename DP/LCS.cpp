#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int m, n;
vector <char> x, y;

void getInput()
{
   cout << "Enter m and n: " << endl;
   cin >> m >> n;

   cout << "Enter x: ";
   for(int i=0; i<m; i++)
   {
    char temp;
    cin >> temp;
    x.push_back(temp);
   }

   cout << "Enter y: ";
   for(int i=0; i<n; i++)
   {
    char temp;
    cin >> temp;
    y.push_back(temp);
   }
}

void LCS()
{
    int c[m][n];
    char b[m][n];

    for(int i=0; i<m; i++)
    {
        c[i][0]= 0;
    }

    for(int j=0; j<n; j++)
    {
        c[0][j]= 0;
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(x[i]== y[j])
        }
    }


}

int main()
{
    getInput();
}