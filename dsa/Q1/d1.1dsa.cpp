#include<iostream>
using namespace std;
int main()
{
    int n,h;
    cout<<"enter number of items:";
    cin>>n;

    int arr[n];

    cout<<"enter items:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"enter number of hours:";
    cin>>h;

    h=h%n;

    cout<<"final display order:";

    for(int i=h;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    for(int i=0;i<h;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
