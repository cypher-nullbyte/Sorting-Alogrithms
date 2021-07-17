// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

void merge(int arr[],int begin,int mid,int end)
{
    int nl=mid-begin+1,nr=end-mid;
    auto* left=new int[nl];
    auto* right=new int[nr];
    
    for(auto i=0;i<nl;i++) left[i]=arr[begin+i];
    for(auto i=0;i<nr;i++) right[i]=arr[mid+1+i];
    
    int i_left=0;
    int i_right=0;
    int i_merged=begin;
    
    while(i_left<nl && i_right<nr)
    {
        if(left[i_left]<right[i_right])  arr[i_merged++]=left[i_left++];
        else  arr[i_merged++]=right[i_right++];
    }
    while(i_left<nl)  arr[i_merged++]=left[i_left++];
    while(i_right<nr)  arr[i_merged++]=right[i_right++];
}


void merge_sort(int arr[], int begin, int end)
{
    if(begin>=end) return;
    auto mid=begin+(end-begin)/2;
    merge_sort(arr,begin,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,begin,mid,end);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    merge_sort(arr,0,n-1);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}


// Time: O(nlogn)
// Aux Space: O(n)
// It is Stable
// See: https://www.youtube.com/watch?v=JSceec-wEyw
