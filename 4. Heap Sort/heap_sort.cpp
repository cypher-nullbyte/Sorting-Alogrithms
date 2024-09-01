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
    

    /*
        We just swap max element in root node (i.e. i-th node).
        Now it could be possible that pushing the i-th node below could not give us heap in child subtree branch.
        Hence, we need to call heapify_max again on max_idx if swapping happens. 
    */
    if(max_idx!=i)
    {
        swap(arr[i],arr[max_idx]);
        heapify_max(arr,n,max_idx); 
    }
}


void heap_sort(int arr[],int n)
{
    //build heap
    /* Something interesting: Building heap using heapify_max should be taking nlog(n). 
      But it takes only O(n).
      Checkout: https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
    */
    for(int i=n/2-1;i>=0;i--)
    {
        heapify_max(arr,n,i);
    }
    
    //swap & delete
    /*
        Note here since heap is already created in above iteration, we need to remove 0-th element
        and swap with last element. 0-th element of a max_heap will always be heighest (its root node of max_heap).
        Now, we've to get sorted array backwards direction.
        We consider heap size to be one less (note i is treated as n in heapify_max func arg call).
        We call heapify for root node always.
    */
    for(int i=n-1;i>0;i--)
    {
        /* move current root to end, this is equivalent to deleting last node (leaf node from complete binary tree)
         and swapping with root node.
        */
        swap(arr[0],arr[i]);
        
        /* Since we deleted leaf from tree, see below its size is reduced and we call heapify_max taking i instead of n.
         Which reduces by 1 in each iteration. Serving the desired purpose.
        */
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

/*  For more Info: 
    https://www.youtube.com/watch?v=MtQL_ll5KhQ
    https://www.geeksforgeeks.org/heap-sort/
    If you completely forgot: https://www.youtube.com/watch?v=HqPJF2L5h9U for intial basic idea.
*/