#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include <chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;

int LinearSearch(char arr[],int len,char key)
{
    int idx=-1;
        for (int i = 0; i < len; i++){
            if (arr[i] == key)
            {
                idx=i;
                break;
            }
        }
    if(idx!=-1) return 1; //if key is found
    return 0; //if key is not found

}


int selectionSort(char arr[],int len)
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
        char t=arr[i];
        arr[i]=arr[idx];
        arr[idx]=t;
    }
    char a[len+1];
    int l=0;
    for(int k=0;k<len;k++){
            if(!LinearSearch(a,l,arr[k])){
                a[l]=arr[k];
                l++;
            }
    }
    for(int m=0;m<l;m++)
    {
        arr[m]=a[m];
    }
    return l;
}


void powerSet(char arr[],int len)
{
    int p_len=pow(2,len);
    vector<string> pset;
    for(int i=0;i<p_len;i++)
    {
         int k=-1;
        char ch[len+1];
        memset(ch,0,sizeof(ch));
        ch[0]=0;

        for(int j=0;j<len;j++)
        {
                if( i & (1 << j))
                    {
                        k++;
                        ch[k]=arr[j];
                    }
        }
    string s(ch);
    pset.push_back(s);
}

	cout<<"The Distinct Set is: "<<pset.size()<<endl;
    int i=0;
	for(string str:pset)
    {
    i++;
    cout<<i<<". Distinct power set is:"<<str<<endl;
    }
}

char *genArray(int n)
{
    char* arr = new char[n];
    for(int i=0;i<n;i++)
        {
        if(rand()%3==0) arr[i]=rand()%10+48;
        else if(rand()%3==1) arr[i]=rand()%26+'a';
        else arr[i]=rand()%26+'A';
        }
    return arr;
}

int main()
{
        srand(time(0));
        fstream file("timeRecordforPowerSet.txt",std::fstream::in | std::fstream::out | std::fstream::app);
        int n;
        cout<<"Enter the number of elements of the set : "<<endl;
        cin>>n;
        //for(int k=5;k<30;k++){
        //    n=k;
        char *arr=genArray(n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        int len=selectionSort(arr,n);
        cout<<"After sorting the characters : "<<endl;
        for(int i=0;i<len;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        auto start = high_resolution_clock::now();

        powerSet(arr,len);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        int x=duration.count();
        file<<n<<" "<<x<<endl;
        cout<<"time required : "<<x<<endl;
        //}
}
