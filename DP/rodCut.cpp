#include<bits/stdc++.h>

using namespace std;

#define numRods 10

struct rod
{
    int length;
    int price;
}rods[100];

int rev[100], cuts[100];

void getInput()
{
    freopen("rod.txt", "r", stdin);
    for(int i = 1; i <= numRods; i++)
    {
        cin >> rods[i].price;
        rods[i].length = i ;
    }
}

int recCutRod(int n);

int cutRod(int n)
{
    for(int i = 1; i <= n; i++)
    {
        rev[i] = -1;
    }

    return recCutRod(n);
}

int recCutRod(int n)
{
    if(n < 0) return 0;  

    if(rev[n] != -1) return rev[n];

    int q;
    if(n == 0) q = 0;
    else
    {
        q = -1;
        for(int i = 1; i <= n; i++)
        {
            if(n-i >= 0)
            {
             // q = max(q, rods[i].price + recCutRod(n - i));
            int m= rods[i].price + recCutRod(n - i);
                if(q < m )
                {
                   // cout<< q << " " << m << " " << " "<< n<< " "<<  i<<  endl;
                    cuts[n]= i;
                    q= m;
                }
            }
        }
        rev[n] = q;
    }
    return q;
}

void rodCuttingProblem()
{
    getInput();
    int n;
    cin >> n;
    cout << "For n= "<< n << " ";
    cout << "The output is: ";
    cout << cutRod(n) << endl;

    // for(int i=0; i<numRods; i++)
    // {
    //     if(cuts[i] != 0)
    //     {
    //         cout<< cuts[i]<< endl;
    //     }
    // }

    cout << "Cuts: ";

    while(n>0)
    {
        cout << cuts[n] << " ";
        n= n-cuts[n];
    }
    cout << endl;
}

int main()
{
    rodCuttingProblem();
}
