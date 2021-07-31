#include<iostream>
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <fstream>
#include <typeinfo>

using namespace std;
using namespace std::chrono;


void printArray(int *a,int n)

{
    for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
    cout<<endl;

}


int *copyArray(int *a,int n)
{
    int *cp=new int[n];
    for(int i=0;i<n;i++)
        cp[i]=a[i];
    return cp;
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
   /*for(int k=0;k<n;k++)
        cout<<arr[k]<<" ";
    cout<<endl;*/
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
   /* for(int k=0;k<n;k++)
        cout<<arr[k]<<" ";
    cout<<endl;*/
    return arr;
}

int *genArray(int n)
{
    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%n;
    }
    return arr;
}

int main()
{
    srand(time(0));
    fstream IBfile("timeMergeSorted.txt");
    fstream IAfile("timeMergeRandom.txt");
    fstream IWfile("timeMergeReversed.txt");
    fstream SBfile("timeQuickSorted.txt");
    fstream SAfile("timeQuickRandom.txt");
    fstream SWfile("timeQuickReversed.txt");
    int time,n,loop;
    loop=1;
    //for test purpose
    /*n=10;
    int *arr=genArray(n); //average
    int *a=genASortedArray(n);//best
    int *ar=genDSortedArray(n);//worst
    insertionSort(arr,n); //ascending order
    selectionSort(arr,n);//ascending order */

    int lenOfArray=34;
    int value[lenOfArray]={10,50,100,150,200,300,500,700,1000,1200,1500,1800,2000,2200,2500,2800,3200,3500,4000,4300,4500,4800,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000,100000};
    for(int l=0;l<lenOfArray;l++){
    n=value[l];
    int *arr=genArray(n);
    int *a=genASortedArray(n);
    int *ar=genDSortedArray(n);
    int *cp1=copyArray(a,n);
    int *cp2=copyArray(arr,n);
    int *cp3=copyArray(ar,n);
    //for best case
    auto start = high_resolution_clock::now();
    MergeSort(a,0,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for sorted case in Merge sort : "<<time<<" nanoseconds"<<endl;
    IBfile<<n<<" "<<time<<endl;
    //for average case
    start = high_resolution_clock::now();
    MergeSort(arr,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for random case in Merge sort  : "<<time<<" nanoseconds"<<endl;
    IAfile<<n<<" "<<time<<endl;
    //for worst case
    start = high_resolution_clock::now();
    MergeSort(ar,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for reversed Sorted case in Merge sort  : "<<time<<" nanoseconds"<<endl;
    IWfile<<n<<" "<<time<<endl;
    cout<<endl;

    //for best case
    start = high_resolution_clock::now();
    quicksort(cp1,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for sorted case in Quick sort : "<<time<<" nanoseconds"<<endl;
    SBfile<<n<<" "<<time<<endl;
    //for average case
    start = high_resolution_clock::now();
    quicksort(cp2,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for random case in Quick sort : "<<time<<" nanoseconds"<<endl;
    SAfile<<n<<" "<<time<<endl;
    //for worst case
    start = high_resolution_clock::now();
    quicksort(cp3,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for reversed sorted case in Quick sort : "<<time<<" nanoseconds"<<endl;
    SWfile<<n<<" "<<time<<endl;
    cout<<endl;
    if(!arr) delete []arr;
    if(!ar) delete []ar;
    if(!a) delete []a;
    if(!cp1) delete []cp1;
    if(!cp2) delete []cp2;
    if(!cp3) delete []cp3;
    }
}

