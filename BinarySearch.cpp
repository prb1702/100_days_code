#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int binarySearch(int a[],int key,int low,int high)
{
    if(low<=high)
    {
        int mid = low + (high-low)/2;
        if(key==a[mid])
        {
            return mid;
        }
        else if(key < a[mid])
        {
            return binarySearch(a,key,low,mid-1);
        }
        else
        {
            return binarySearch(a,key,mid+1,high);
        }
    }
    return -1;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements : ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int i=1;
    while(i)
    {
        int key;
        cout << "Enter the element you want to search : ";
        cin >> key;

        int ind;
        ind = binarySearch(arr,key,0,n-1);

        if(ind== -1)
        {
            cout << "Element not found!" << endl;
        }
        else
        {
            cout << "Element found at index : " << ind << endl;
        }

        cout << "Do you want to continue ? 1 for YES and 0 for NO" << endl;
        cin >> i;

    }
    return 0;
}
