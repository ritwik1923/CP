
#include<iostream>
using namespace std;
int a[10][10],n,m;
void turlematrix(int ini, int last,int blast)
{
     cout<<ini<<"  "<<last<<"  "<<blast<<"\n";
    for(int i=ini;i<=last;i++) {
       cout<<a[ini][i]<<"_";
    }cout<<endl;
    for(int i=ini+1;i<=blast;i++) {
       cout<<a[i][last]<<"+";
    }cout<<endl;
    if(ini!=blast){
    for(int i=last-1;i>=ini;i--) {
       cout<<a[blast][i]<<"*";
    }cout<<endl;}
    if(ini!=last) {
    for(int i=blast-1;i>ini;i--) {
       cout<<a[i][ini]<<"@";
    }
    cout<<endl;
    }
}

int main()  {
    int i , j , b , c ;
    cin>>m>>n;
//int a[n][n];
    for( i = 0; i < m ; i++) {
     for( j = 0 ; j < n ; j++) {
      cin>>a[i][j];
     }
    }
     for( i = 0; i < m ; i++) {
     for( j = 0 ; j < n ; j++) {
      cout<<a[i][j]<<" ";
     }
     cout<<"\n";
    }
    int run=min(n,m);
    if(run%2==0)
        b=m/2;
    else
        b=(m/2)+1;
    for(i=0;i<b;i++) {
        if(n-1-i<=0||m-1-i<=0||i>n-1-i||i>m-1-i) break;
        else
    turlematrix(i,n-1-i,m-1-i);
    }

    return 0;
}

