#include <iostream>
using namespace std;
int binarysearch(int arr[],int left, int right, int x)
{
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]<x)
        {
            left=mid+x;
        }
        else
        {
            right=mid-1;
        }
        return -1;
    }
}

int main()
{
    int num;
    int myarr[10];
    int output;

    cout<<"Enter 10 numbers in Ascending Order:"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>myarr[i];
    }
    cout<<"Enter the number you want to search in the array: "<<endl;
    cin>>num;
    output=binarysearch(myarr,0,9,num);
    if (output==-1)
    {
        cout<<"No Match Found"<<endl;
    }
    else
    {
        cout<<"Number Found at Index position:"<<output<<endl;
    }
    return 0;
}