// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm> // max_element
using namespace std;

void count_sort(int arr[],int n,int expon)
{
    int count[10]={0};
    int output[n];
    
    // fill count arr
    for(int i=0;i<n;i++)
        count[(arr[i]/expon)%10]++;
        
    // Add prev elem count    
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    
    // Build the output arry
    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/expon)%10]-1]=arr[i];
        count[(arr[i]/expon)%10]--;
    }    
    // Copy Output Array back
    for(int i=0;i<n;i++) arr[i]=output[i];
}


void radix_sort(int arr[],int n)
{
    int mx=*max_element(arr,arr+n);
    
    for(int i=1;mx/i>0;i*=10)
        count_sort(arr,n,i);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    radix_sort(arr,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}



//Time: O(n)
// To see Count Sort working: https://www.youtube.com/watch?v=imqr13aIBAY
