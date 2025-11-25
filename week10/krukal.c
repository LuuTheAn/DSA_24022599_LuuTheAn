
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[1000], sz[1000];

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

vector<Edge> Kruskal(int n, vector<Edge> E) {
    sort(E.begin(), E.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<Edge> T;
    int k = 0;
    int idx = 0;

    while (k < n - 1) {
        Edge e = E[idx++];
        int i = Find(e.u);
        int j = Find(e.v);

        if (i != j) {
            T.push_back(e);
            Union(i, j);
            k++;
        }
    }

    return T;
}
