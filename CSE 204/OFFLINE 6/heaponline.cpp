#include<iostream>
using namespace std;

class PriorityQueue
{
    int *arr;
    int Size,Max;
    public:
        PriorityQueue(int k)
        {
            Size=0;
            Max=k;
            arr=new int[Max];
        }

        void Insert(int x)
        {
            Size++;
            arr[Size-1]=x;
            heapify(arr,Size,Size-1);
        }

        void heapify(int a[],int n,int i)
        {
            int p=(i-1)/2;

            if(a[i]>a[p])
                {
                    int t=a[i];
                    a[i]=a[p];
                    a[p]=t;
                    heapify(a,n,p);
                }
        }

        void Maxheapify(int *a,int n,int i)
        {
            int m=i;
            int l=2*i+1;
            int r=2*i+2;
            if(l<n && a[l]>a[m])
                m=l;
            if(r<n && a[r]>a[m])
                m=r;
            if(m!=i)
            {
                 int t=a[i];
                    a[i]=a[m];
                    a[m]=t;
                Maxheapify(a,n,m);
            }
        }

        int findMax()
        {
            if(Size==0)
            {
                cout<<"Queue Underflow"<<endl;
                return 999999;
            }
            return arr[0];
        }

        int ExtractMax()
        {
            int m=999999;
            if(Size!=0)
            {
            m=arr[0];
            int last=arr[Size-1];
            arr[0]=last;
            Size=Size-1;
            Maxheapify(arr,Size,0);
            }
            else{
                cout<<"Queue is empty"<<endl;
                return 999999;
            }
            return m;
        }

        void IncreaseKey(int i,int key)
        {
            if(i<0 || i>=Size)
            {
                cout<<"Queue overflow"<<endl;
                return;
            }
            if(key <arr[i])
            {
                cout<<"New key is smaller"<<endl;
                return;
            }
            arr[i]=key;
            heapify(arr,Size,i);
        }

        void DecreaseKey(int i,int key)
        {
            if(i<0 || i>=Size)
            {
                cout<<"Queue overflow"<<endl;
                return;
            }

            arr[i]=key;
            Maxheapify(arr,Size,i);
        }

        void Print()
        {
            if(Size==0)
            {
                cout<<"queue is empty "<<endl;
                return;
            }
            for(int i=0;i<Size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }

};

int main()
{
int k;
    cout<<"Enter the value of k : "<<endl;
    cin>>k;
    PriorityQueue p(k);
    int c;
    int cn=0;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Insert" <<"              " << "3: Exit" <<endl;
    cout << "2: k th smallest" <<endl;
    cin >>c;
    switch(c)
    {
    case 1:
        int x;
        cout<<"Enter the element :"<<endl;
        cin>>x;
        if(cn<k){
            p.Insert(x);
            cn++;
            }
        else if(cn==k)
            {
            if(p.findMax()>x){
                p.ExtractMax();
                p.Insert(x);
                }
            }
        break;
    case 2:
        if(cn<k)
                cout<<"undefined"<<endl;
        else
        {
            cout<<"kth smallest : "<<p.findMax()<<endl;
        }
        break;
    case 3:
        return 0;
    }
    }
}
