#include<iostream>
using namespace std;
int main()
{
    char str[100],longest[100];
    int i=0,len=0,max=0;
    cout<<"Enter sentence: ";
    cin.getline(str,100);
    while(str[i]!='\0')
    {
        if(str[i]!=' ')
        {
            len++;
        }
        else
        {
            if(len>max)
            {
                max=len;
                for(int j=0;j<len;j++)
                {
                    longest[j]=str[i-len+j];
                }
                longest[len]='\0';
            }
            len=0;
        }
        i++;
    }
    if(len>max)                                  //for the last word
    {
        max=len;
        for(int j=0;j<len;j++)
        {
            longest[j]=str[i-len+j];
        }
        longest[len]='\0';
    }
    cout<<"Longest word="<<longest<<endl;
    cout<<"Length="<<max<<endl;
    return 0;
}
