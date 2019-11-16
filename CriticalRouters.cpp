#include<iostream> 
#include <list> 
#define NIL -1 
using namespace std; 
class Graph { 
    int V;    
    list<int> *adj; 
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
public: 
    Graph(int V); 
    void addEdge(int v, int w);
    void AP();
};  
Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<int>[V]; 
} 
void Graph::addEdge(int v, int w) { 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
void Graph::APUtil(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) { 
    static int time = 0; 
    int children = 0; 
    visited[u] = true; 
    disc[u] = low[u] = ++time; 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
        int v = *i; 
        if (!visited[v]) { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
            low[u]  = min(low[u], low[v]); 
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
void Graph::AP(){ 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V];
    for (int i = 0; i < V; i++) { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap); 
    for (int i = 0; i < V; i++) 
        if (ap[i] == true) 
            cout << i << " "; 
} 
int main() { 
    cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 

    cout << "\nArticulation points in fourth graph \n"; 
    //[[0,1], [0, 2], [1, 3], [2, 3], [2, 5], [5, 6], [3,4]]
    Graph g4(7); 
    g4.addEdge(0, 1); 
    g4.addEdge(0, 2); 
    g4.addEdge(1, 3); 
    g4.addEdge(2, 3); 
    g4.addEdge(2, 5); 
    g4.addEdge(5, 6); 
    g4.addEdge(3, 4); 
    g4.AP(); 

    cout << "\nArticulation points in 5th graph \n"; 
    Graph g5(2); 
    g5.addEdge(0, 1); 
    g5.AP(); 

    cout << "\nArticulation points in 6th graph \n"; 
    Graph g6(3); 
    g6.addEdge(0, 1); 
    g6.addEdge(2, 1); 
    g6.addEdge(2, 0); 
    g6.AP(); 

    cout << "\nArticulation points in 7th graph \n"; 
    Graph g7(8); 
    g7.addEdge(1, 0); 
    g7.addEdge(5, 1); 
    g7.addEdge(2, 4); 
    g7.addEdge(5, 4); 
    g7.addEdge(4, 3); 
    g7.addEdge(6, 5);
    g7.addEdge(7, 5); 
    g7.AP(); 

    cout << "\nArticulation points in 8th graph \n"; 
    Graph g8(6); 
    g8.addEdge(0, 1); 
    g8.addEdge(2, 1); 
    g8.addEdge(0, 2); 
    g8.addEdge(5, 4); 
    g8.addEdge(5, 3); 
    g8.addEdge(3, 4);
    g8.addEdge(3, 2); 
    g8.AP(); 

    cout << "\nArticulation points in 9th graph \n"; 
    Graph g9(3); 
    g9.addEdge(0, 1); 
    g9.addEdge(0, 2); 
    g9.AP(); 

    cout << "\nArticulation points in 10th graph \n"; 
    Graph g10(0); 
    g10.AP(); 

    cout << "\nArticulation points in 11th graph \n"; 
    Graph g11(4); 
    g11.addEdge(0, 1); 
    g11.addEdge(0, 2); 
    g11.addEdge(1, 3); 
    g11.addEdge(2, 3); 
    g11.AP(); 
  
    return 0; 
} 