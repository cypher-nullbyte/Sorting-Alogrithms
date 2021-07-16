// #include<bits/stdc++.h>
#include<iostream>
using namespace std;


int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}


void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    quick_sort(arr,0,n-1);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}


// Avg Time: O(nlogn), worst: O(n^2)
// Aux Space: O(n) (worst case)
// See: https://www.youtube.com/watch?v=PgBzjlCcFvc
