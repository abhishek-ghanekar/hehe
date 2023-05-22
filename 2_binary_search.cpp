#include<iostream>
using namespace std;
void binarySearchRecursion(int start , int end,int arr[],int target) {
    if(start > end) {
        cout << "element not found";
        return ;
    }
    int mid = (start+end)/2;
    if(arr[mid] == target) {
        cout << "element found at position : " << mid + 1  << endl;
        return ;
    }else if(arr[mid] < target) {
        binarySearchRecursion(mid+1,end,arr,target);
    }else {
        binarySearchRecursion(start,mid-1,arr,target);
    }
}
void binarySearchIteration(int start,int end,int arr[],int target) {
   while(start <= end) {
        int mid = (start+end)/2;
        if(arr[mid] == target) {
            cout << "element found at position " << mid + 1 << endl;
            break;
        }else if(arr[mid] < target) {
            start = mid+1;
        }else {
            end = mid-1;
        }
    }
    if(start > end) {
        cout << "element not found" << endl;
    }
}
int main()
{
    int arr[50];
    cout << "enter number of elements " << endl;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    cout << "enter a number to find" << endl;
    int search;
    cin >> search;
    int start = 0;
    int end = n-1;
    cout << "binary search using recursion" << endl;
    binarySearchRecursion(start,end,arr,search);
    cout << endl;
    cout << "binary search using iteration" << endl;
    binarySearchIteration(start,end,arr,search);
    return 0;
}