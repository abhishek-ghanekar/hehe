#include<iostream>
using namespace std;
int partition(int a[],int start,int end) {
    int v = a[start];
    int i = 1;
    int j = end + 1;
    int temp;
    do {
        do {
          i++;
        }while(a[i]<v && i <=end);

        do{
          j--;
        }while(a[j] > v);

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        
    }while(i < j);
    a[start] = a[j];
    a[j] = v;
    return j;
}
void quick_sort(int a[],int start,int end) {
    if(start < end) {
        int j = partition(a,start,end);
        quick_sort(a,start,j-1);
        quick_sort(a,j+1,end);
    }
}

int main()
{
    int a[50];
    cout << "how many elements? ";
    int n;
    cin >> n;
    cout << "enter array elements :";
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    return 0;
}