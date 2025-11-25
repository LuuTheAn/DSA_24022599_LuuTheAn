#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, w;
};

vector<Edge> adj[1000];

void Prim(int n, int s) {
    int key[1000];
    int nearV[1000];
    int inMST[1000];

    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        nearV[i] = s;
        inMST[i] = 0;
    }

    key[s] = 0;

    for (int step = 1; step <= n; step++) {

        int v = -1;
        int minKey = INF;

        for (int i = 1; i <= n; i++) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                v = i;
            }
        }

        inMST[v] = 1;

        if (v != s)
            cout << nearV[v] << " - " << v << "\n";

        for (auto e : adj[v]) {
            int w = e.to;
            if (!inMST[w] && e.w < key[w]) {
                key[w] = e.w;
                nearV[w] = v;
            }
        }
    }
}
