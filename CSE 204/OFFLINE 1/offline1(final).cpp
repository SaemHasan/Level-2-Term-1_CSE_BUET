#include<iostream>
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <fstream>
#include <typeinfo>

using namespace std::chrono;
using namespace std;

int LinearSearch(int arr[],int len,int key)
{

    int idx;
    auto start = high_resolution_clock::now();
    for(int j=0;j<10000;j++){
        idx=-1;
        for (int i = 0; i < len; i++){
            if (arr[i] == key)
            {
                idx=i;
                break;
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);



    int x=duration.count();
    x=x/10000;

    if(idx!=-1) cout<<"key : "<<key <<" is found in the index :"<<idx<<" by Linear Search"<<endl;
    else
        cout<<"key : "<<key <<" is not found in the array by Linear Search"<<endl;
    cout <<"For n= "<<len <<", Time for Linear Search: "<<x <<" nanoseconds"<< endl;
    cout<<endl;

    return x;

}

int BinarySearch(int arr[],int len,int key)
{
    int i,j,mid,idx;
    auto start = high_resolution_clock::now();

    for(int k=0;k<10000000;k++){
        i=0;
        j=len-1;
        idx=-1;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(key==arr[mid]) {
                idx=i;
                break;
            }
            else if(key>arr[mid]) i=mid+1;
            else j=mid-1;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    int x=duration.count();
    x=x/10000000;

    if(idx!=-1) cout<<"key : "<<key <<" is found in the index :" <<idx<<" by Binary Search"<<endl;
    else
        cout<<"key : "<<key <<" is not found in the array by Binary Search"<<endl;

    cout <<"For n= "<<len <<", Time for Binary Search : "<<x <<" nanoseconds" << endl;
    cout<<endl;

    return x;
}

int *genArray(int n)
{
    int* arr = new int[n];
    arr[0]=rand()%10;
    for(int i=1;i<n;i++)
    {
        int x=(rand()%10)+1;
        arr[i]=x+arr[i-1];
    }
    return arr;
}


int main()
{
    fstream Linear_file("Linear_file.txt");
    fstream Binary_file("Binary_file.txt");
    srand(time(0));
    int lenOfArray=33;
    int a[lenOfArray]={10,50,100,150,200,300,500,700,1000,1200,1500,1800,2000,2200,2500,2800,3200,3500,4000,4300,4500,4800,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000};

   for(int k=0;k<lenOfArray;k++)
   {
       int *ar=genArray(a[k]);
       int key=rand()%a[k];

       /*cout<<key<<endl;
       for(int i=0;i<10;i++)
        cout<<ar[i]<< " ";
       cout<<endl;*/

     Linear_file<<a[k] <<" "<<LinearSearch(ar,a[k],key);
     Linear_file<<endl;

     Binary_file<<a[k] <<" "<<BinarySearch(ar,a[k],key);
     Binary_file<<endl;
   }

   return 0;
}
