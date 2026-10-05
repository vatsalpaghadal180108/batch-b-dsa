#include<iostream>


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

