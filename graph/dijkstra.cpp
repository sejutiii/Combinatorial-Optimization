#include<bits/stdc++.h>
#define n 20
#define INF 10000000

using namespace std;


int numVertices, numEdges;
string vertices[n], source, destination;
string graph[n][2];
int w[n][n];
int d[n], p[n];

int getIndexof(string vertex)
{
    for(int i=1; i<= numVertices; i++)
    {
        if(vertex == vertices[i]) return i;
    }
    return -1;
}

void getInput()
{
    int u, v, index=1, g_w[n];
    freopen("dijkstra.txt", "r", stdin);
    cin >> numEdges;
    for(int i=1; i<=numEdges; i++)
    {
        cin >> graph[i][0] >> graph[i][1];
        cin >> g_w[i];

        if(i==1)
        {
            vertices[index]= graph[i][0];
            index++;
            vertices[index]= graph[i][1];
            index++;
        }
        
        else
        {
            bool flag=false;
            for(int j=1; j<index; j++)
            {
                if(graph[i][0]== vertices[j])
                {
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                vertices[index]= graph[i][0];
                index++;
            }

            flag=false;
            for(int j=1; j<index; j++)
            {
                if(graph[i][1]== vertices[j])
                {
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                vertices[index]= graph[i][1];
                index++;
            }
        }
    }

    numVertices= index-1;

    cin >> source >> destination;

    for(int i=1; i<=numEdges; i++)
    {
        u= getIndexof(graph[i][0]);
        v= getIndexof(graph[i][1]);
        w[u][v]= g_w[i];
    }
}

void initialize()
{
    int ind_source= getIndexof(source);
    for(int i=1; i<= numVertices; i++)
    {
       d[i]= INF;
       p[i]= -1; // -1 -> null
    }
    d[ind_source]= 0;
}

void relax(int u, int v)
{
    if(d[v] > d[u]+ w[u][v])
    {
        d[v]= d[u]+ w[u][v];
        p[v]= u;
    }
}

void Dijkstra()
{
    initialize();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    pair<int, int> temp;
    for(int i=1; i<=numVertices; i++)
    {
        temp.first= d[i];
        temp.second= i;
        queue.push(temp);
    }

    while(!queue.empty())
    {
        temp= queue.top();
        int u= temp.second;
        queue.pop();
        for(int v=1; v<= numVertices; v++)
        {
            if(w[u][v] != 0) relax(u, v);
        }
    }
}

void print_path(int index)
{
    if(index== -1) return;
    print_path(p[index]);
    cout << vertices[index] << " -> ";
}

int main()
{
    getInput();
    Dijkstra();
    int ind_destination= getIndexof(destination);
    print_path(ind_destination);
    cout << d[ind_destination] << endl;
}