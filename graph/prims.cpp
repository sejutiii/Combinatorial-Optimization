#include<bits/stdc++.h>
using namespace std;

#define Max 20

int numVertices, numEdges;
int graph[Max][Max] = {0};

map<string, int> names;
int previous[Max];
int key[Max];
bool inMST[Max];

void relax(int u, int v) {
    if (key[v] > graph[u][v] && graph[u][v] != 0) {
        key[v] = graph[u][v];
        previous[v] = u;
    }
}

void MST() {
    for (auto u : names) {
        key[u.second] = INT_MAX;
        previous[u.second] = -1;
        inMST[u.second] = false;
    }

    key[names.begin()->second] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({key[names.begin()->second], names.begin()->second});

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (inMST[u]) {
            continue; // Skip if u is already in MST
        }

        inMST[u] = true;

        for (int v = 1; v <= names.size(); v++) {
            if (graph[u][v] && !inMST[v]) {
                relax(u, v);
                q.push({key[v], v});
            }
        }
    }
}