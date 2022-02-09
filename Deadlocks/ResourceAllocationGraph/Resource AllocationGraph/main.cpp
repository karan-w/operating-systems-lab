#include<iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
        
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    
    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    if(g.isCyclic())
        cout << "The system is in a deadlock state.\n";
    else
        cout << "The system is not in a deadlock state.\n";
    return 0;
}
