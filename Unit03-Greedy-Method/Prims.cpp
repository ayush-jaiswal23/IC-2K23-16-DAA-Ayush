#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Pair type representing {weight, vertex}
typedef pair<int, int> pii;

// Function to find the total weight of the Minimum Spanning Tree using Prim's Algorithm
int primMST(int V, const vector<vector<pair<int, int>>>& adj) {
    // Min-priority queue to store {weight, vertex}
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> inMST(V, false);
    int mstSum = 0;

    // Start with vertex 0, weight 0
    pq.push({0, 0});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int u = p.second;
        int wt = p.first;

        // If the vertex is already included in MST, skip it
        if (inMST[u]) continue;

        // Include vertex in MST and add its weight to the total sum
        inMST[u] = true;
        mstSum += wt;

        // Traverse all adjacent vertices
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If the adjacent vertex is not in MST, push it to priority queue
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    return mstSum;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Helper lambda to add undirected edges (u, v, weight)
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    int totalWeight = primMST(V, adj);
    cout << "Sum of weights of the Minimum Spanning Tree: " << totalWeight << endl;

    return 0;
}