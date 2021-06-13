// C++ implementation of simple method to find count of 
// pairs with given sum. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns number of pairs in arr[0..n-1] with sum equal 
// to 'sum' 
int gettrisCount(int arr[], int n, int sum) 
{ 
	unordered_map<int, int> m; 

	// Store counts of all elements in map m 
	for (int i=0; i<n; i++) 
		m[arr[i]]++; 

	// iterate through each element and increment the 
	// count (Notice that every pair is counted twice) 
	//time complexcity is O(n)
  //  map<pair<int,int>,int> tri;
    for (int i=0; i<n; i++) 
	{ 
		//twice_count = m[sum-arr[i]]; 
        
            for(int j=i+1;j<n-2;j++) {
                if(m.find(sum-arr[i]-arr[j])!=m.end())
                {cout<<(sum-arr[i]-arr[j])<<" "<<arr[i]<<" "<<arr[j]<<"\n";
                m[a[i]]--;m[sum-arr[i]-arr[j]]--;m[a[j]]--;
                //tri.insert(make_pair(a[i],a[j]),sum-a[i]-a[j]);
                }
            }
          
	} 
 /*
 for (const auto &entry: tri)
	{
		auto key_pair = entry.first;
		std::cout << "{" << key_pair.first << "," << key_pair.second << "}, "
				  << entry.second << '\n';
	}*/

	// return the half of twice_count 
} 

// Driver function to test the above function 
int main() 
{ 
	int arr[] = {1, 1,5, 7, -1, 5} ; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int sum = 7; 
	cout << "Count of pairs is "
		<< gettrisCount(arr, n, sum); 
	return 0; 
} 
