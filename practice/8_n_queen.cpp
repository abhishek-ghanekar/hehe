#include<iostream>
using namespace std;
#define n 8
void printMatrix(int board[n][n]) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }cout << endl;
    }
}
bool isSafe(int board[n][n],int row,int col) {
  //check the column
  for(int i=0;i<n;i++) {
    if(board[i][col]) {
        return false;
    }
  }
  //check top left diagonal
  for(int i)
}
bool solveNQueen(int board[n][n],int col) {
    if(col >= n) {
        return true;
    }
    for(int i=0;i<n;i++) {

        if(isSafe(board,i,col)) {
          board[i][col] = 1;
          if(solveNQueen(board,col+1)) {
            return true;
          }
          board[i][col] = 0;
        }
    }
    return false;
};
bool solve() {
    int board[n][n] = {0};

    if(solveNQueen(board,0)) {
        printMatrix(board);
    }
}
int main()
{
    solve();
    return 0;
}