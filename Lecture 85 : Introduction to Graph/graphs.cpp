#include <iostream>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

class graph {
    public:

    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // create an edge fro, u to v

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
        
    }

    void printedAdjList()
    {
        for(auto i : adj)
        {
            cout << i.first << "-> ";
            for(auto j : i.second)
            {
                cout << j << "-> ";
            }cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // creaating an undirected graph
        g.addEdge(u, v, 0);
    }
    
    // printitng graph
    g.printedAdjList();
    
    return 0;
}
