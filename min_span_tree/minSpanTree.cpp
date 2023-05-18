#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph
{
    int V;                                  // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list
};

// Function to create a new graph
Graph *createGraph(int V)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->adjList.resize(V);
    return graph;
}

// Function to add an undirected edge to the graph
void addEdge(Graph *graph, int src, int dest, int weight)
{
    graph->adjList[src].push_back(make_pair(dest, weight));
    graph->adjList[dest].push_back(make_pair(src, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(Graph *graph)
{
    int V = graph->V;
    vector<int> key(V, INT_MAX);   // Key values used to pick minimum weight edge
    vector<bool> mstSet(V, false); // To keep track of vertices included in MST
    vector<int> parent(V, -1);     // Array to store constructed MST

    // Priority queue to store vertices along with their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0; // Start with the first vertex
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        // Traverse all adjacent vertices of u
        // graph  <v,weight>
        for (auto &neighbor : graph->adjList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not yet included in MST and weight of (u,v) is smaller than current key of v
            if (mstSet[v] == false && weight < key[v])
            {
                // Update key value and parent index of v
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the constructed MST
    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main()
{
    int V = 7; // Number of vertices in the graph
    Graph *graph = createGraph(V);

    // Add edges
    addEdge(graph, 0, 1, 6);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 0, 5, 3);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 6);
    addEdge(graph, 5, 6, 1);

    // Find the minimum spanning tree
    primMST(graph);

    return 0;
}
