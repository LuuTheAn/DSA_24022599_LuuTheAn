#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, w;
};

vector<Edge> adj[1000];
int D[1000];

void Dijkstra(int s, int n) {

    for (int v = 1; v <= n; v++)
        D[v] = INF;
    D[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> P;

    for (int v = 1; v <= n; v++)
        if (v != s) P.push({D[v], v});

    P.push({0, s});

    while (!P.empty()) {

        int u = P.top().second;
        int distU = P.top().first;
        P.pop();

        if (distU != D[u]) continue;

        for (auto e : adj[u]) {
            int v = e.to;
            int w = e.w;

            if (D[u] + w < D[v]) {
                D[v] = D[u] + w;
                P.push({D[v], v});
            }
        }
    }
}
