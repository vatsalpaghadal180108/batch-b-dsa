#include<iostream>
using namespace std;
int linearsearch(string arr[],int n,string key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int recursivesearch(string arr[],int n,string key,int i)
{
    if(i>=n)
        return -1;

    if(arr[i]==key)
        return i;

    return recursivesearch(arr,n,key,i+1);
}

int main()
{
    int n;
    cout<<"enter number of vehicles: ";
    cin>>n;

    string arr[n];

    cout<<"enter license plates:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    string key;
    cout<<"enter target plate: ";
    cin>>key;

    int ans1=linearsearch(arr,n,key);

    if(ans1!=-1)
        cout<<"iterative search: found at position "<<ans1+1<<endl;
    else
        cout<<"iterative search: not found"<<endl;

    int ans2=recursivesearch(arr,n,key,0);

    if(ans2!=-1)
        cout<<"recursive search: found at position "<<ans2+1<<endl;
    else
        cout<<"recursive search: not found"<<endl;

    return 0;
}
