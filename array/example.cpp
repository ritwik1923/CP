#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        
        if(n==1)
        cout<<arr[0]<<endl;
        else
        {
        
            int maxProduct=1;
            int minProduct=1;
            int best=arr[0];
            
            for(int i=0;i<n;i++)
            {
                if(arr[i]<0)
                {
                    //swaping
                    int temp=minProduct;
                    minProduct=maxProduct;
                    maxProduct=temp;
                }
                
                maxProduct=max(((maxProduct%1000000007)*(arr[i]%1000000007))%1000000007,arr[i]%1000000007);
                minProduct=min(((minProduct)%1000000007*(arr[i])%1000000007)%1000000007,arr[i]%1000000007);
                best=max(best%1000000007,maxProduct%1000000007);
            }
            
            cout<<best<<endl;
        }
        
    }
	return 0;
}