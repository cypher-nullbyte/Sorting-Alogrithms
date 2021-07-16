// #include<bits/stdc++.h>
#include<iostream>
using namespace std;


void heapify_max(int arr[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int max_idx=i;
    if(arr[l]>arr[max_idx] && l<n) max_idx=l;
    if(arr[r]>arr[max_idx] && r<n) max_idx=r;
    
    if(max_idx!=i)
    {
        swap(arr[i],arr[max_idx]);
        heapify_max(arr,n,max_idx);
    }
}


void heap_sort(int arr[],int n)
{
    //build heap
    for(int i=n/2-1;i>=0;i--)
    {
        heapify_max(arr,n,i);
    }
    
    //swap & delete
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify_max(arr,i,0);
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    heap_sort(arr,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}


// Time: O(nlogn)
// Space: O(1)

// Not Stable

// For more Info: https://www.youtube.com/watch?v=MtQL_ll5KhQ
