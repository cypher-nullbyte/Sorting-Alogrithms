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
        int temp=arr[min_idx];
        while(min_idx>i) arr[min_idx--]=arr[min_idx-1];    // this loop ensures stability (note in normal selection-sort we did swapping).
        arr[i]=temp;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}

//     https://www.geeksforgeeks.org/stable-selection-sort/
