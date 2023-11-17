#include<bits/stdc++.h>

using namespace std;

#define SIZE 20
#define MAX 10e6

int numVertices, numEdges;
vector<string> vertices(SIZE);
vector<vector<int>> capacity;
vector<vector<int>> flow;
string graph[SIZE][SIZE];
vector<int> path;
int max_capacity= MAX;
string source, destination;

vector<bool> visited(SIZE, false);
vector<int> parent(SIZE, -1);

int indexOf(string s, int numVertex)
{
    for(int i=0; i<numVertex; i++)
    {
        if(vertices[i]== s) return i;
    }
    return -1;
}

void getInput() {
    cin >> numEdges;
    int index = 0;
    vector<int> cap(numEdges);
    for (int i = 0; i < numEdges; i++) {
        cin >> graph[i][0] >> graph[i][1];
        cin >> cap[i];

        for (int k = 0; k < 2; k++) {
            bool flag = false;
            for (int j = 0; j < index; j++) {
                if (graph[i][k] == vertices[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                vertices[index] = graph[i][k];
                index++;
            }
        }
    }
    numVertices = index;
    capacity.resize(numVertices, vector<int> (numVertices));
    int u, v;
    for (int i = 0; i < numEdges; i++) {
        u = indexOf(graph[i][0], numVertices);
        v = indexOf(graph[i][1], numVertices);
        capacity[u][v] = cap[i];
    }

    cin >> source >> destination;
}

void generatePath(int dst_index)
{
   if(dst_index== -1) return;
   generatePath(parent[dst_index]);
   path.push_back(dst_index);
}

bool BFS(int src_index, int dst_index)
{
    path.clear();
    for(int i=0; i<SIZE; i++)
    {
        visited[i]= false;
    }
    queue<int> q;
    q.push(src_index);
    visited[src_index]= true;
    parent[src_index]= -1;
    while(!q.empty())
    {
        int v= q.front();
        if(v== dst_index)
        {
            generatePath(dst_index);
            return true;
        }
        q.pop();

        for(int i=0; i<numVertices; i++)
        {
            if(capacity[v][i]!=0 && visited[i]==false)
            {
                q.push(i);
                visited[i]= true;
                parent[i]= v;
                if(capacity[v][i] < max_capacity) max_capacity= capacity[v][i];
            }
        }
    }
    return false;
}

void ford_fulkerson(int src_index, int dst_index)
{
    //flow[u][v] = 0 -> global
    int total_flow=0;
    flow.resize(numVertices, vector<int>(numVertices));
    while(BFS(src_index, dst_index))
    {
        for(int i=0; i<path.size()-1; i++)
        {
            if(capacity[path[i]][path[i+1]] != 0)
            {
                flow[path[i]][path[i+1]] += max_capacity;
                capacity[path[i]][path[i+1]] -= max_capacity;
            }
            else flow[path[i+1]][path[i]] -= max_capacity;
        }
        total_flow += max_capacity;
    }
    cout << "flow= " << total_flow << endl;
}

void print_Flow_network()
{
    for(int i=0; i<numVertices; i++)
    {
        for(int j=0; j<numVertices; j++)
        {
            if(flow[i][j] != 0)
            {
                cout << vertices[i] << " -> " << vertices[j];
                cout << "  " << flow[i][j] << endl; 
            }
        }
    }
}

void print_Residual_network()
{
    for(int i=0; i<numVertices; i++)
    {
        for(int j=0; j<numVertices; j++)
        {
            if(capacity[i][j] != 0)
            {
                cout << vertices[i] << " -> " << vertices[j];
                cout << "  " << capacity[i][j] << endl; 
            }
        }
    }
}

int main()
{
    freopen("temp.txt", "r", stdin);
    getInput();
    ford_fulkerson(indexOf(source, numVertices), indexOf(destination, numVertices));
    print_Flow_network();
}