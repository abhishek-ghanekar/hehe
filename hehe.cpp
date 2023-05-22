#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int v,vector<list<pair<int,int>>> adj,int s) {
    vector<int> dist(v);
    for(auto i:dist) i=1e9;
    dist[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    // the pair format is node, distance
    pq.push({0,0});
    while(!pq.empty()) {
        int node = pq.top().first;
        int dis = pq.top().second;
        pq.pop();
        for(auto edge:adj[node]) {
            int edgeNode = edge.first;
            int weight = edge.second;
            if(dis + weight < dist[edgeNode]) {
                dist[edgeNode] = dis + weight;
                pq.push({edgeNode,dist[edgeNode]});
            }
        }
    }
    return dist;
}
int main()
{
    int v;
    cout << "enter number of vertices";
    cin >> v;
    int edges;
    cout << "enter number of edges"<< endl;
    cin >> edges;
    vector<list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++) {
      int a,b,c;
      cin >> a >> b >> c;
      adj[a].push_back({b,c});
    }

    vector<int> result = dijkstra(v,adj,0);
    for(auto i:result) {
        cout << i << " ";
    }
    return 0;
}