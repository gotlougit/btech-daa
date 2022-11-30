// PRIMS CLRS
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void printGraph(vector<pair<int, int>> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << i << " --- " << adj[i][j].first << "  (" << adj[i][j].second << ")  ";
        }
        cout << endl;
    }
}
void prims(vector<pair<int, int>> adj[], int v, int src)
{
    vector<int> key(v, INT_MAX);
    vector<int> parent(v, -1);
    vector<int> inMST(v, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, src));
    key[src] = 0;
    parent[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u] == true)
        {
            continue;
        }

        inMST[u] = true;
        for (auto i : adj[u])
        {
            int x = i.first;
            int w = i.second;
            if (inMST[x] == false && key[x] > w)
            {
                key[x] = w;
                pq.push(make_pair(key[x], x));
                parent[x] = u;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
}
int main()
{
    int v = 6;
    vector<pair<int, int>> adj[v];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 1);
    addEdge(adj, 3, 5, 2);
    addEdge(adj, 4, 5, 3);
    // addEdge(adj, 6, 7, 15);
    
    printGraph(adj, v);
    cout << endl;
    prims(adj, v, 0);
}
