#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int minKey(int key[], bool mstSet[], int n) {
    int minValue = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < minValue) {
            minValue = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    cout << "Source -> Destination : Weight\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " -> " << i << " : " << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }

    cout << "Total cost of MST = " << totalCost << "\n";
}

int main() {
    int n;
    int graph[MAX][MAX];

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, n);

    return 0;
}
