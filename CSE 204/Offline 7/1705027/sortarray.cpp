#include <cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void printArray(int *a,int n)
{
    for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
    cout<<endl;

}

int Partition(int *a,int l,int h)
{
        int pi=a[h];
        int i=l-1;
        for(int j=l;j<h;j++)
        {
            if(a[j]<=pi)
            {
                i++;
                swap(a[i],a[j]);
            }
        }
        swap(a[i+1],a[h]);
        return i+1;
}

void quicksort(int *a,int l,int h)
{
    if(l<h)
    {
        int p=Partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}

void Merge(int *a,int p,int q,int r)
{
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int *L,*R;
    L=new int[n1+1];
    R=new int[n2+1];
    for(i=0;i<n1;i++)
        L[i]=a[p+i];
    for(j=0;j<n2;j++)
        R[j]=a[q+j+1];
    i=0;
    j=0;
    L[n1]=9999999;
    R[n2]=9999999;
    //printArray(L,n1+1);
    //printArray(R,n2+1);
    for(int k=p;k<=r;k++)
    {
        if(L[i]<R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
    }
}


void MergeSort(int *a,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        Merge(a,p,q,r);
    }
}

int *genArray(int n)
{
    int* ar = new int[n];
    for(int i=0;i<n;i++)
    {
        ar[i]=rand()%1000000;
    }
    return ar;
}

int *genDSortedArray(int n)
{
    int* arr = new int[n];
    arr[0]=rand()%n+99874;
    for(int i=1;i<n;i++)
    {
        int x=(rand()%10)+1;
        arr[i]=arr[i-1]-x;
        //if(arr[i]<0) arr[i]=rand()%n;
    }
    return arr;
}


int *genASortedArray(int n)
{

    int* arr = new int[n];
    arr[0]=rand()%10;
    for(int i=1;i<n;i++)
    {
        int x=(rand()%10)+1;
        arr[i]=x+arr[i-1];
    }
//printArray(arr,n);
    return arr;
}

int *copyArray(int *a,int n)
{
    int *cp=new int[n];
    for(int i=0;i<n;i++)
        cp[i]=a[i];
    return cp;
}

int main()
{
    srand(time(0));
    int choice, n=0;
    int *arr,*cp,time;
    while(1)
    {
        printf("1. Generate average case\n");
        printf("2. Generate best case\n");
        printf("3. Generate worst case\n");
        printf("4. Apply Merge sort\n");
        printf("5. Apply Quicksort\n");
        printf("6. Print array\n");
        cout<<"7. Exit"<<endl;
        printf("> ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Number of elements: ");
            scanf("%d", &n);
            if(!arr) delete []arr;
            arr=genArray(n);
            if(!cp) delete []cp;
            cp=copyArray(arr,n);
            //printArray(arr,n);
            break;
    case 2:
            printf("Number of elements: ");
            scanf("%d", &n);
            if(!arr) delete []arr;
            arr=new int[n];
            for(int i=0;i<n;i++) cin>>arr[i];
            if(!cp) delete []cp;
            cp=copyArray(arr,n);
            //printArray(arr,n);
            // do yourself
            break;

        case 3:
            printf("Number of elements: ");
            scanf("%d", &n);
            if(!arr) delete []arr;
            arr=genDSortedArray(n);
            if(!cp) delete []cp;
            cp=copyArray(arr,n);
            //printArray(arr,n);
            // do yourself
            break;

        case 4:
            {
            printf("Applying merge sort\n");
            auto start = high_resolution_clock::now();
            MergeSort(arr,0,n-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            time=duration.count();
            printf("Time taken to finish:");
            cout<<time<<" nanoseconds"<<endl;
        }
            break;

        case 5:
            {
            printf("Applying quicksort\n");
            auto start = high_resolution_clock::now();
            quicksort(cp,0,n-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            time=duration.count();
            printf("Time taken to finish:");
            cout<<time<<" nanoseconds"<<endl;
        }
            break;

        case 6:
            //printf("Array\n");
            if(n!=0){
                cout<<"Array :"<<endl;
                printArray(arr,n);
                cout<<"copy array :"<<endl;
                printArray(cp,n);
            }
            // do yourself
            break;
        case 7:
            return 0;

        }
    }
}

