#include<bits/stdc++.h>

using namespace std;

int numVertices, numEdges;
vector<char> vertices;
vector<pair<int, pair<char,char>>> edges;

void getInput()
{
    //freopen("file.txt", "r", stdin);
    cin >> numVertices >> numEdges;
    getchar();
    for(int i=0; i<numVertices; i++)
    {
        char temp;
        cin >> temp;
        vertices.push_back(temp);
    }

    for(int i=0; i<numEdges; i++)
    {
        char u, v;
        int w;
        cin >> u >> v;
        cin >> w;
        getchar();
        pair<int, pair<char,char>> edge;
        edge.first= w;
        edge.second.first= u;
        edge.second.second= v;
        edges.push_back(edge);
    }

}