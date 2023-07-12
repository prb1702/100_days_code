#include <iostream>

using namespace std;

class arr
{
public:
    void bubbleSort(int*, int n);
    void insertionSort(int[], int n);
    void selectionSort(int[], int n);
    void mergeSort(int[],int low,int high);
    void mergee(int [],int low,int mid,int high);
    void quickSort(int[],int p,int q);
};

/*
    Best Case -> O(n)
    Worst Case -> O(n^2)
    Avg case -> O(n^2)
*/
/*
    the insertion sort and the bubble sort algorithms behave differently. For each iteration, insertion sort finds the proper place for the
    ith element amongst the already sorted i-1 elements, situated at the beginning of the array. Conversely, bubble sort compares and swaps
    adjacent elements in each iteration. Bubble sort performs poorly compared to the insertion sort due to the high number of swaps,
*/

void arr :: bubbleSort(int p[], int n)
{
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j+1]<p[j])
            {
                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << p[i] << "\t";
    }
    cout << endl;
}

/*
    Best Case -> O(n)
    Worst Case -> O(n^2)
    Avg case -> O(n^2)
*/

void arr :: insertionSort(int p[], int n)
{
    int curr;
    int j;
    for(int i=0;i<n;i++)
    {
        curr = p[i];
        j=i-1;
        while(curr<p[j])
        {
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=curr;
    }

    for(int i=0;i<n;i++)
    {
        cout << p[i] << "\t";
    }
    cout << endl;
}

/*
    Best Case -> O(n^2)
    Worst Case -> O(n^2)
    Avg case -> O(n^2)
*/

void arr :: selectionSort(int a[], int n)
{
    int minn,temp,min_ind;

    for(int i=0;i<n-1;i++)
    {
        minn=a[i];
        min_ind=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<minn)
            {
                minn=a[j];
                min_ind=j;
            }
        }
        a[min_ind]=a[i];
        a[i]=minn;
    }

    for(int i=0;i<n;i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

/*
    O(nlogn) for all cases
*/

void arr :: mergee(int a[],int low,int mid,int high)
{
    int i,j,k;
    i=low;
    k=low;
    j=mid+1;
    int b[high+1];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else if(j>high)
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }

    for (int i = low; i <= high; i++) {
        a[i] = b[i];
    }

    /*for(int i=0;i<high+1;i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;*/

}

void arr :: mergeSort(int p[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (high+low)/2;
        mergeSort(p,low,mid);
        mergeSort(p,mid+1,high);
        mergee(p,low,mid,high);
    }
}


/*
    Best Case -> O(nlogn)
    Avg case -> O(nlogn)
    Worst Case -> O(n^2)
*/

void arr :: quickSort(int a[],int p, int eend)
{
    int temp;

    if(p<eend)
    {
        int too_big_ind, too_small_ind,pivot;
        pivot=p;
        too_big_ind = p+1;
        too_small_ind = eend;


         while(too_big_ind < too_small_ind)
         {
             while(a[too_big_ind]<a[pivot] && too_big_ind < eend)
             {
                 too_big_ind++;
             }
             while(a[too_small_ind]>a[pivot] && too_small_ind > 0)
             {
                 too_small_ind--;
             }
             if(too_big_ind<too_small_ind)
             {
                 temp = a[too_big_ind];
                 a[too_big_ind] = a[too_small_ind];
                 a[too_small_ind] = temp;
             }
         }
         if(a[pivot] >= a[too_small_ind])
         {
             temp = a[too_small_ind];
             a[too_small_ind] = a[pivot];
             a[pivot] = temp;

             quickSort(a,p,too_small_ind-1);
             quickSort(a,too_small_ind+1,eend);
         }
    }
}

int main()
{
    arr a;

    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;

    int p[n];

    cout << "Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
    }

    for(int i=0;i<n;i++)
    {
        cout << p[i] << "\t";
    }
    cout << endl;

    int i=1, choice;

    while(i)
    {
        cout << "\n1 for Bubble Sort\n2 for Insertion Sort\n3 for Selection Sort\n4 for MergeSort\n5 for QuickSort";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            a.bubbleSort(p,n);
            break;
        case 2:
            a.insertionSort(p,n);
            break;
        case 3:
            a.selectionSort(p,n);
            break;
        case 4:
            a.mergeSort(p,0,n-1);
            for(int i=0;i<n;i++)
            {
                cout << p[i] << "\t";
            }
            cout << endl;
            break;
        case 5:
            a.quickSort(p,0,n-1);
            for(int i=0;i<n;i++)
            {
                cout << p[i] << "\t";
            }
            cout << endl;
            break;
        default:
            cout << "Invalid choice!!" << endl;
        }
    }

    return 0;
}
