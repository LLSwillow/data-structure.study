#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char A[101];
    gets(A);
    int i=0,j=strlen(A)-1;
    if(j<0)cout << "error\n";
    else
    {
        for(i=0;i<j;i++)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            j--;
        }
    }
    cout<<A<<endl;
    return 0;
} 