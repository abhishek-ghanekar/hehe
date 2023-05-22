#include <iostream>
using namespace std;
int min(int, int);
int a[10][10],i,j,k,n;
int min(int a, int b)
{
if(a<b)
return a;
else
return b;
}
int main() {
 cout<<"Enter n = ";
 cin>>n;
 cout<<"Enter matrix = ";
 for(i=1;i<=n;i++){
 for(j=1;j<=n;j++){
 cin>>a[i][j];
 if(a[i][j]==0){
 a[i][j]=999;}
 }
 }
 
 
 
 for(k=1;k<=n;k++)
 { for(i=1;i<=n;i++)
 { for(j=1;j<=n;j++)
 {
 if(i==j){
 a[i][j]=0;}
else
 {
 a[i][j]= min(a[i][j], (a[i][k]+a[k][j]));}
 }
 }
 }
cout<<"\n";
 for(i=1;i<=n;i++){
 for(j=1;j<=n;j++){
 cout<<a[i][j]<<" ";}
 cout<<"\n";}
return 0;
}