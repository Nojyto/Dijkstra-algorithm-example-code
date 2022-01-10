#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e8

typedef pair<int, int> iPair;

class Graph{
private:
    int V;
    vector<vector<iPair>> adj;
  
public:
    Graph(const int V){
        this->V = V;
        adj.resize(V);
    }
  
    void addEdge(const int u, const int v, const int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void shortestPath(const int src){
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        pq.push(make_pair(0, src));
    
        vector<int> dist(V, INF);
        dist[src] = 0;
    
        while(!pq.empty()){
            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();
    
            for(auto i : adj[u]){
                int v = i.first, weight = i.second;

                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    
        printf("V\tDist\n");
        for(int i = 0; i < V; i++)
            printf("%d\t%d\n", i, dist[i]);
    }
};
  
int main()
{
    Graph g(9);
  
    g.addEdge(0, 1,  4);
    g.addEdge(0, 7,  8);
    g.addEdge(1, 2,  8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3,  7);
    g.addEdge(2, 8,  2);
    g.addEdge(2, 5,  4);
    g.addEdge(3, 4,  9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6,  2);
    g.addEdge(6, 7,  1);
    g.addEdge(6, 8,  6);
    g.addEdge(7, 8,  7);
  
    g.shortestPath(0);
}