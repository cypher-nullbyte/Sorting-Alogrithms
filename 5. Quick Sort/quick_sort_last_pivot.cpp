#include<bits/stdc++.h>
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

// Don't want to swap the pivot separately, which is at index high. Include pivot and traverse j until <=high.
// Moreover, i will be displaced one step ahead. So reduce 1 from i and return as new pivot position.
int partition2(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    return i-1;
}

// https://www.youtube.com/watch?v=3g32Z8OkZQU
// But in this code, pivot was included in first while loop. 
int partition_middle_pivot(int arr[], int low, int high)
{
    int pivot=arr[low+ (high-low)/2];
    int i=low;
    int j=high;
    while(true)
    {
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        
        if(i>=j) return j;
        swap(arr[i],arr[j]);
    }
}

void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition2(arr,low,high);
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


/*
6
4 5 2 1 3 5
*/

// Avg Time: O(nlogn), worst: O(n^2)
// See: https://www.youtube.com/watch?v=PgBzjlCcFvc (for first method, considering last element as pivot)
