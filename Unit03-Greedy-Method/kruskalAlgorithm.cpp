#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int u, v, weight;

    // Comparator function to sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Disjoint Set Union (DSU) with Path Compression and Union by Rank
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union function by rank
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }
};

// Function to run Kruskal's Algorithm
void kruskalsMST(int V, vector<Edge>& edges) {
    // 1. Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<Edge> mst;
    int mst_weight = 0;

    cout << "Edges in the constructed MST:\n";
    for (const Edge& edge : edges) {
        int root_u = dsu.find(edge.u);
        int root_v = dsu.find(edge.v);

        // If including this edge doesn't cause a cycle, include it in MST
        if (root_u != root_v) {
            dsu.unite(root_u, root_v);
            mst.push_back(edge);
            mst_weight += edge.weight;
            cout << edge.u << " -- " << edge.v << " == " << edge.weight << "\n";
        }
    }

    cout << "Total Weight of Minimum Spanning Tree: " << mst_weight << "\n";
}

int main() {
    // Number of vertices (0-indexed)
    int V = 4;

    // List of edges: {u, v, weight}
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalsMST(V, edges);

    return 0;
}