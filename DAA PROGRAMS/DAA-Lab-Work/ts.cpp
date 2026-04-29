#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void topologicalSort(int V, vector<int> adj[], map<int, int>& inDegree, vector<int> nodes) {
    queue<int> q;
    vector<int> result;

    // 1. Add all nodes with in-degree 0 to the queue
    for (int u : nodes) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        // 2. Reduce in-degree of neighbors
        for (int v : adj[u]) {
            inDegree[v]--;
            // 3. If in-degree becomes 0, add to queue
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Output the result
    cout << "Topological Sort: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " -> ");
    }
    cout << endl;
}

int main() {
    // Define nodes from your image
    vector<int> nodes = {1, 2, 3, 4, 5, 6};
    
    // Adjacency list (using a large enough size or a map)
    vector<int> adj[7]; 
    map<int, int> inDegree;

    // Initialize in-degrees to 0
    for(int n : nodes) inDegree[n] = 0;

    // Define edges based on your image:
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        inDegree[v]++;
    };

    addEdge(5, 2);
    addEdge(5, 1);
    addEdge(2, 4);
    addEdge(2, 6);
    addEdge(1, 6);
    addEdge(4, 3);
    addEdge(6, 3);

    topologicalSort(6, adj, inDegree, nodes);

    return 0;
}