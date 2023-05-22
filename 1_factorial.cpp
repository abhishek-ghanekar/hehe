#include<iostream>
using namespace std;
//recursive method
int factorialRecursive(int n) {
    if(n == 0) return 1;
    return n * factorialRecursive(n-1);
}
//iterative method
int factorialIterative(int n) {
    int ans = 1;
    for(int i=n;i>=1;i--) {
        ans *= i;
    }
    return ans;
}
int main()
{
    int n;
    cout << "enter number to find the factorial : ";
    cin >> n;
    cout << "factorial using recursion is" << endl;
    cout << factorialRecursive(n) << endl;
    cout << "factorial using iteration is" << endl;
    cout << factorialIterative(n) << endl;
    return 0;
}