#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int knaps(int n,int m,int w[],int p[]) {
    int knapsack[n+1][m+1];

    for(int j=0;j<=m;j++) {
        knapsack[0][j] = 0;
    }
    for(int i=0;i<=n;i++) {
        knapsack[i][0] = 0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(w[i-1] <= j) {
                // that means we can pick the object
                int pick = p[i-1] + knapsack[i-1][j-w[i-1]];
                int notPick = knapsack[i-1][j];
                knapsack[i][j] = max(pick,notPick);
            }else {
                knapsack[i][j] = knapsack[i-1][j];
            }
        }
    }
    return knapsack[n][m];

}
int main()
{ 
    cout << "enter number of items" << endl;
    int n;
    cin >> n;
    int w[n];
    int p[n];
    for(int i=0;i<n;i++) {
         cout << "enter weight and profit" ;
         cin >> w[i] >> p[i];
    }  
    cout << endl;
    cout << "Enter Capacity Of KnapSack" << endl;
    int m;
    cin >> m;
    int result = knaps(n,m,w,p);
    cout << "maximum value that can be stored is " << result;

     return 0;
}