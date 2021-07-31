#include<iostream>
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <fstream>
#include <typeinfo>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[],int len)
{
    int i,j,m,k;
    for(j=1;j<len;j++)
    {
        i=0;
        while(arr[j]>arr[i])
            i=i+1;
        m=arr[j];
        for(k=0;k<j-i-1;k++)
            arr[j-k]=arr[j-k-1];
        arr[i]=m;
    }
}
void selectionSort(int arr[],int len)
{
    int idx;

    for(int i=0;i<len-1;i++)
    {
        idx=i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j]<arr[idx])
                idx=j;
        }
        int t=arr[i];
        arr[i]=arr[idx];
        arr[idx]=t;
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
    fstream IBfile("timeInsertionBest.txt");
    fstream IAfile("timeInsertionAverage.txt");
    fstream IWfile("timeInsertionWorst.txt");
    fstream SBfile("timeSelectionBest.txt");
    fstream SAfile("timeSelectionAverage.txt");
    fstream SWfile("timeSelectionWorst.txt");
    int time,n,loop;
    loop=1;
    //for test purpose
    /*n=10;
    int *arr=genArray(n); //average
    int *a=genASortedArray(n);//best
    int *ar=genDSortedArray(n);//worst
    insertionSort(arr,n); //ascending order
    selectionSort(ar,n);//ascending order
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }*/
    int lenOfArray=33;
    int value[lenOfArray]={10,50,100,150,200,300,500,700,1000,1200,1500,1800,2000,2200,2500,2800,3200,3500,4000,4300,4500,4800,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000};
    for(int l=0;l<lenOfArray;l++){
    n=value[l];
    int *arr=genArray(n);
    int *a=genASortedArray(n);
    int *ar=genDSortedArray(n);
    int arr1[n],ar1[n],a1[n];
    for(int z=0;z<n;z++)
    {
        arr1[z]=arr[z];
        ar1[z]=ar[z];
        a1[z]=a[z];
    }
    //for best case
    auto start = high_resolution_clock::now();
    for(int i=0;i<loop;i++)
        {
            insertionSort(a,n);
        }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for best case in insertion sort : "<<time<<" nanoseconds"<<endl;
    IBfile<<n<<" "<<time<<endl;
    //for average case
    start = high_resolution_clock::now();
    for(int i=0;i<loop;i++)
        {
            insertionSort(arr,n);
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for average case in insertion sort  : "<<time<<" nanoseconds"<<endl;
    IAfile<<n<<" "<<time<<endl;
    //for worst case
    start = high_resolution_clock::now();
    for(int i=0;i<loop;i++)
        {
            insertionSort(ar,n);
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for worst case in insertion sort  : "<<time<<" nanoseconds"<<endl;
    IWfile<<n<<" "<<time<<endl;
    cout<<endl;
    //for best case
    start = high_resolution_clock::now();
    for(int i=0;i<loop;i++)
        {
            selectionSort(a1,n);
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for best case in selection sort : "<<time<<" nanoseconds"<<endl;
    SBfile<<n<<" "<<time<<endl;
    //for average case
    start = high_resolution_clock::now();
    for(int i=0;i<loop;i++)
        {
            selectionSort(arr1,n);
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for average case in selection sort : "<<time<<" nanoseconds"<<endl;
    SAfile<<n<<" "<<time<<endl;
    //for worst case
    start = high_resolution_clock::now();
    for(int i=0;i<loop;i++)
        {
            selectionSort(ar1,n);
        }
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    time=duration.count();
    cout<<"n = "<<n<<", time for worst case in selection sort : "<<time<<" nanoseconds"<<endl;
    SWfile<<n<<" "<<time<<endl;
    cout<<endl;
    }
}
