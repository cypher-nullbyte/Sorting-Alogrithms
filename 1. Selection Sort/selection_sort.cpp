
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        int min_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        if(min_idx!=i)
        {
            arr[i]=arr[min_idx]+arr[i]-(arr[min_idx]=arr[i]);  // this is simply inplace swap operation.
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

// Time Complexity: O(n)
// Auxilarry Space Complexity: O(1)

// Becauses Swapping involved, hence its not stable sorting. 
