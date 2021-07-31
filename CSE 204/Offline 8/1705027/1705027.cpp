#include<iostream>
using namespace std;

class Set
{
    int *p,*r,Max;
public:
    int v;
    Set()
    {
        Max=100000;
        v=0;
        p=new int[Max];
        r=new int[Max];
        for(int i=0;i<Max;i++)
        {
            p[i]=v;
            r[i]=v;
        }
    }
    ~Set()
    {
        delete []p;
        delete []r;
    }
    void Make_set(int x)
    {
        p[x]=x;
        r[x]=0;
    }

    int Find(int x)
    {
        if(x!=p[x])
            p[x]=Find(p[x]);
        return p[x];
    }

    void Union(int x,int y)
    {
        int a=Find(x);
        int b=Find(y);
        if(a==b)
            return;
        if(r[a]>r[b])
            p[b]=a;
        else{
            p[a]=b;
            if(r[a]==r[b])
                r[b]++;
        }
    }

    int pFind(int x)
    {
        if(x!=p[x])
            pFind(p[x]);
        return p[x];
    }

    void print(int x)
    {
        int a=pFind(x);
        cout<<a<<" ";
        for(int i=0;i<Max;i++)
        {
            if(i!=a && a==pFind(i))
                cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main()
{
   /* int m;
    cout<<"enter the maximum input of the set :";
    cin>>m;*/
    Set s;
    int c;
    int l=s.v;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Make-Set" <<"            " << "4: Print" <<endl;
    cout << "2: Find-Set" <<"            "<< "5: Exit" <<endl;
    cout << "3: Union"<<endl;
    cin >>c;
    switch(c)
    {
    case 1:
        int x;
        cout<<"Enter the element greater than 0:"<<endl;
        cin>>x;
        if(x>l )
            s.Make_set(x);
        else
            cout<<"Wrong input"<<endl;
        break;
    case 2:
        int f;
        cout<<"Enter the element to find :"<<endl;
        cin>>f;
        if(f>l && s.pFind(f)!=0)
            cout<<"the set is : "<<s.Find(f)<<endl;
        else if(f>l && s.pFind(f)==0)
            cout<<"This element is not in the set"<<endl;
        else
            cout<<"Wrong input"<<endl;
        break;
    case 3:
        int x1,y;
        cout<<"Enter the first element :"<<endl;
        cin>>x1;
        cout<<"Enter the second element :"<<endl;
        cin>>y;
        if(x1>l && y>l && s.pFind(x1)!=0 && s.pFind(y)!=0)
                s.Union(x1,y);
        else
            cout<<"Wrong input"<<endl;
        break;
    case 4:
        int p;
        cout<<"Enter the set to print:"<<endl;
        cin>>p;
        if(p>l && s.pFind(p)!=0)
            s.print(p);
        else
            cout<<"Wrong input"<<endl;
       break;
    case 5:
         return 0;
    }
    }
}
