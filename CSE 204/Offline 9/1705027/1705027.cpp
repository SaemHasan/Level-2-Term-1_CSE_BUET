#include<iostream>
#include <algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

class   Time{
public:
    int start,finish;
    Time()
    {
        int st=rand()%24;
        int fn=st+1+rand()%(24-st);
        start=st;
        finish=fn;
    }
    void print()
    {
        cout<<"["<<start<<"-"<<finish<<")"<<" ";
    }

    bool operator<(Time &o)
    {
        if(this->finish==o.finish)
        {
            return this->start<o.start;
        }
        else{
            return this->finish<o.finish;
        }
    }
};

int FindMaxAct(Time *t,int n)
{
    int i,j,c=1;
    i=0;
    t[i].print();
    for(int j=1; j<n; j++)
    {
        if(t[j].start>=t[i].finish)
        {
            c++;
            i=j;
            t[i].print();
        }
    }
    return c;
}

int main()
{
    srand(time(0));
    int n;
    cout<<"Enter the number of activity : "<<endl;
    cin>>n;

    Time t[n];

    sort(t,t+n);

    cout<<"All activities after sorting by finish time"<<endl;
    for(int i=0;i<n;i++)
    {
        t[i].print();
    }

    int maxAct;
    cout<<endl<<"Solution : "<<endl;
    maxAct=FindMaxAct(t,n);
    cout<<endl;
    cout<<"Maximum Number of Activity : "<<maxAct<<endl;
}

