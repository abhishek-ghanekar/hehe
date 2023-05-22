// this is the solution for the n queens problem 
#include<iostream>
using namespace std;
#define n 8
void printSolution(int board[n][n]) {
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }cout << endl;
      }
}
bool isSafe(int board[n][n],int row ,int col) {
    // check the entire column
    for(int i=0;i<col;i++) {
        if(board[row][i]) {
            return false;
        }
    }
    // we dont need to check the row as we place all queens in different rows

    //check the top left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--) {
        if(board[i][j]) {
            return false;
        }
    }

    //check the bottom left diagonal
    for(int i=row, j=col;i<n && j>=0;i++,j--){
        if(board[i][j]) {
            return false;
        }
    }
    return true;

}
bool solveNqueen(int board[n][n],int col) {
    if(col >= n) {
        return true;
    }

    for(int i=0;i<n;i++) {
        if(isSafe(board,i,col)) {
            board[i][col] = 1;
            if(solveNqueen(board,col+1) == true) {
                 return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
bool solve() {
    int board[n][n] = {0};
    if(solveNqueen(board,0) == false) {
        cout << "solution does not exist";
        return false;
    }
    printSolution(board);
    return true;
}
int main()
{
    solve();
    return 0;
}