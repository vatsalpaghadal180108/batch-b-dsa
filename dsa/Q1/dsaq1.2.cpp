#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of books required: ";
    cin>>n;
    int book[100];
    for(int i=0;i<n;i++)
    {
        cin>>book[i];
    }
	for(int i=0;i<n;i++)
    {
        int count=0;
		for(int j=0;j<n;j++)
        {
            if(book[i]==book[j])
            {
                count++;
            }
        }
		int flag=0;                                                 //id don't repeat again
		for(int k=0;k<i;k++)
        {
            if(book[k]==book[i])
            {
                flag=1;
            }
        }
		if(count>1 && flag==0)
        {
        	cout<<"the book issued more than once:";
            cout<<book[i]<<endl;
        }
    }

    return 0;
}
