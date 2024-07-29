#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> costs(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> costs[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, 0});
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1), rank(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    int totalCost = 0;
    for (const Edge& edge : edges) {
        if (find(edge.u, parent) != find(edge.v, parent)) {
            unite(edge.u, edge.v, parent, rank);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (find(i, parent) == i) {
            totalCost += costs[i];
        }
    }

    cout << totalCost << endl;
    return 0;
}
