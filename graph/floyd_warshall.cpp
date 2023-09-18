#include<bits/stdc++.h>
#define n 100
#define inf 100000;

using namespace std;

int w[n][n];
int d[n][n];
int p[n][n];
string graph[n][2];
int g_w[n];
string vertex[n];

int indexOf(string s, int numVertex)
{
    for(int i=1; i<=numVertex; i++)
    {
        if(vertex[i]== s) return i;
    }
    return -1;
}

void initialize(int numVertex)
{
    for(int i=1; i<=numVertex; i++)
    {
        for(int j=1; j<=numVertex; j++)
        {
            d[i][j]= w[i][j];
            if(i==j || w[i][j]== 100000)
            {
                p[i][j]= 0;
            }
            else if(i !=j && w[i][j]< 100000)
            {
                p[i][j]= i;
            }
        }
    }
}

void fw(int numVertex)
{

    initialize(numVertex);
    for(int k=1; k<=numVertex; k++)
    {
        for(int i=1; i<=numVertex; i++)
        {
            for(int j=1; j<=numVertex; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j]= d[i][k] + d[k][j];
                    p[i][j]= p[k][j];
                }
            }
        }
    }
}

void printMat(int numVertex)
{
    for(int i=1; i<=numVertex; i++)
    {
        for(int j=1; j<=numVertex; j++)
        {
            cout << d[i][j] << "  ";
        }
        cout << endl;
    }
}

void printpath(int s, int t)
{
    if(p[s][t]==0) 
    {
        cout << "No path" <<endl;
        return;
    }
    else if(p[s][t] == s)
    {
        cout << vertex[s] << " ";
    }
    else{
        printpath(s, p[s][t]);
        printpath(p[s][t], t);
    }

}

void path(string s, string t, int num)
{
    int u, v;
    u= indexOf(s, num);
    v= indexOf(t, num);

    cout << "The shortest path from " << s << " to " << t << " is- ";
    printpath(u, v);

    cout << endl << "weight= " << d[u][v]<<endl;
}

int main()
{
    int numVertex, numEdge, u, v, index=1;

    freopen("input.txt", "r", stdin);
    cin >> numEdge;
    for(int i=1; i<=numEdge; i++)
    {
        cin >> graph[i][0] >> graph[i][1];
        cin >> g_w[i];

        if(i==1)
        {
            vertex[index]= graph[i][0];
            index++;
            vertex[index]= graph[i][1];
            index++;
        }
        
        else
        {
            bool flag=false;
            for(int j=1; j<index; j++)
            {
                if(graph[i][0]== vertex[j])
                {
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                vertex[index]= graph[i][0];
                index++;
            }

            flag=false;
            for(int j=1; j<index; j++)
            {
                if(graph[i][0]== vertex[j])
                {
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                vertex[index]= graph[i][0];
                index++;
            }
        }
    }

    numVertex= index-1;

    for(int i=1; i<=numVertex; i++)
    {
        for(int j=1; j<=numVertex; j++)
        {
            if(i==j)
                w[i][j]= 0;
            else w[i][j]= inf;
        }
    }

    for(int i=1; i<=numEdge; i++)
    {
        u= indexOf(graph[i][0], numVertex);
        v= indexOf(graph[i][1], numVertex);
        w[u][v]= g_w[i];
    }

    fw(numVertex);
    printMat(numVertex);
    
    string a, b;
    cout <<"Enter the edges: ";
    cin >> a >> b;
    path(a, b, numVertex);
}