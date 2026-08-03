#include<iostream>
using namespace std;

int binarySearch(int a[],int n,int key)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==key)
            return mid;
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int recursiveSearch(int a[],int low,int high,int key)
{
    if(low>high)
        return -1;
    int mid=low+(high-low)/2;
    if(a[mid]==key)
        return mid;
    else if(key<a[mid])
        return recursiveSearch(a,low,mid-1,key);
    else
        return recursiveSearch(a,mid+1,high,key);
}

int main()
{
    int n;
    cout<<"enter number of books:";
    cin>>n;
    int a[n];
    cout<<"enter sorted book codes:"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int key;
    cout<<"enter target code:";
    cin>>key;
    int ans=binarySearch(a,n,key);
    if(ans!=-1)
        cout<<"iterative search:found at position "<<ans+1<<endl;
    else
        cout<<"iterative search: not found"<<endl;
    ans=recursiveSearch(a,0,n-1,key);
    if(ans!=-1)
        cout<<"recursive search:found at position "<<ans+1<<endl;
    else
        cout<<"recursive search:not found"<<endl;
    return 0;
}
