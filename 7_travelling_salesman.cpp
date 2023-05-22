#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int tsp[10][10] = {{12,30,33,10,45},{56,22,9,15,18},{29,13,8,5,12},{33,28,16,10,3},{1,4,30,24,20}};
int visited[10];
int n;
int cost = 0;
void travellingsalesman(int c) {
    int k;
    int adj_vertex = INT_MAX;
    int min = INT_MAX;
    visited[c] = 1;
    cout << c + 1 << " ";
    for(k=0;k<n;k++) {
        if((tsp[c][k] != 0) && (visited[k] == 0)) {
            if(tsp[c][k] < min) {
                min = tsp[c][k];
            }
            adj_vertex = k;
            
        }
    }
    if(min != INT_MAX) {
        cost = cost + min;
    }
    if(adj_vertex == INT_MAX) {
        adj_vertex = 0;
        cout << adj_vertex + 1;
        cost = cost  + tsp[c][adj_vertex];
        return ;
    }
    travellingsalesman(adj_vertex);
}
int main()
{
    int i,j;
    n = 5;
    for(int i=0;i<n;i++) {
        visited[i] = 0;

    }
    cout << endl;
    cout << "shortest path" ;
    travellingsalesman(0);
    cout << endl;
    cout << cost;
    return 0;
}