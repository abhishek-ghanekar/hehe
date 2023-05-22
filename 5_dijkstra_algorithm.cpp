#include<iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> dijkstra(int v,vector<vector<int>> &matrix,int s) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(v);
    for(int i=0;i<v;i++) dist[i] = 1e9;
    dist[s] = 0;
    pq.push({0,s});
    while(!pq.empty()) {
       int dis = pq.top().first;
       int node = pq.top().second;
       pq.pop();
       for(auto it:matrix[node]) {
          int edgeWeight = it[1];
          int adjacentNode = it[0];
          if(dis + edgeWeight < dist[adjacentNode]) {
            dist[adjacentNode] = dis + edgeWeight;
          }
       }
    }
}
int main()
{
    // we need to make an adjacency list
    int v;
    cout << "enter total number of vertices" << endl;
    cin >> v;
    vector<vector<int>> matrix;
    for(int i=0;i<v;i++) {
        int a,b;
        cin >> a >> b;
        matrix.push_back({a,b});
    }
    vector<int> ans = dijkstra(v,matrix,0);

    return 0;
}