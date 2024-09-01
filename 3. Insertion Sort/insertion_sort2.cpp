#include<bits/stdc++.h>

using namespace std;

int main()
{   int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    for(int i=1; i<n;i++)
    {
        int j=i-1;

    /* Notice Carefully, it is actually same as the first method. 
    Just different lines of code for same type of insertion.
    */
        while(j>=0 && arr[j+1] < arr[j])
        {
            arr[j]=arr[j+1]+arr[j]- (arr[j+1]=arr[j]); // swap
            j--;
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl<<endl;
    }
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

// Time: O(n^2)
