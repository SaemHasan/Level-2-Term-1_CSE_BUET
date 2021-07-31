#include<iostream>
using namespace std;

class PriorityQueue
{
    int *arr;
    int Size,Max;
    public:
        PriorityQueue()
        {
            Size=0;
            Max=10;
            arr=new int[Max];
        }

    void resize()
    {
        int *temp,i=0,s;
         temp=new int[Max];
        while(i<Max){
            temp[i]=arr[i];
            i++;
        }
        s=i;
        i=0;
        delete []arr;
        Max+=10;
        arr=new int[Max];
        while(i<s){
            arr[i]=temp[i];
            i++;
        }
        delete []temp;
    }

        void Insert(int x)
        {
            if(Size==Max)
            {
                resize();
                cout<<"Resize complete"<<endl;
            }
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
    PriorityQueue p;
    int c;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Insert" <<"              " << "5: Decrease Key" <<endl;
    cout << "2: Find Max" <<"            " << "6: Print" <<endl;
    cout << "3: Extract Max"<<"         "<<"7: Exit"<<endl;
    cout<<"4: Increase Key"<<endl;
    cin >>c;
    switch(c)
    {
    case 1:
        int x;
        cout<<"Enter the element :"<<endl;
        cin>>x;
        p.Insert(x);
        break;
    case 2:
        if(p.findMax()!=999999)
        cout<<"the maximum is : "<<p.findMax()<<endl;
        break;
    case 3:
        int v;
        v=p.ExtractMax();
        if(v!=999999)
            cout<<"Max : "<<v<<endl;
        break;
    case 4:
        int i,k;
        cout<<"enter the position : "<<endl;
        cin>>i;
        cout<<"enter the key : "<<endl;
        cin>>k;
        p.IncreaseKey(i-1,k);
       break;
    case 5:
        //int i,k;
        cout<<"enter the position : "<<endl;
        cin>>i;
        cout<<"enter the key : "<<endl;
        cin>>k;
        p.DecreaseKey(i-1,k);
        break;
    case 6:
        p.Print();
        break;
    case 7:
        return 0;
    }
    }
}
