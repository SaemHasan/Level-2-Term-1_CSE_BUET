#include<iostream>
using namespace std;

class STACK
{
    int maxsize;
    int tos;
    int *stk;

public:
    STACK()
    {
        maxsize=10;
        stk=new int[10];
        tos=0;
    }
    int Maxsize()
    {
        return maxsize;
    }
    void resize()
    {
        int *temp,i=0,s;
         temp=new int[maxsize];
        while(i<maxsize){
            temp[i]=stk[i];
            i++;
        }
        s=i;
        i=0;
        delete []stk;
        tos=0;
        maxsize+=10;
        stk=new int[maxsize];
        while(i<s){
            push(temp[i]);
            i++;
        }
        cout<<"Now max size of stack is : "<<maxsize<<endl;
        delete []temp;
    }

    bool empty()
    {
        return (!tos);
    }

    int size()
    {
        return tos;
    }

    int top()
    {
        if(tos==0)
        {
            cout<<"Stack is empty"<<endl;
            return -99999;
        }
        return stk[tos-1];
    }

    void push(int x)
    {
        if(size()==maxsize)
        {
            cout<<"stack is full!!"<<endl;
            return;
        }
        stk[tos++]=x;
    }

    void pop()
    {
       if(!empty()) {
            cout<<"pop successful"<<endl;
            --tos;
            return;
       }
       cout<<"stack is empty !"<<endl;
    }
    void exit()
    {
    while(!empty()){
        cout << top()<<endl;
        pop();
        }
    }
};


class Queue
{
    int *q;
    int fr,re,maxsize;
public:
    Queue()
    {
        q=new int[10];
        maxsize=10;
        fr=0;
        re=0;
    }
    int Maxsize()
    {
        return maxsize;
    }
    void resize()
    {
        int *temp,i=0,s;
        temp=new int[maxsize];
        while(i<maxsize){
            temp[i]=q[i];
            i++;
        }
        s=i;
        i=0;
        delete []q;
        re=0;
        maxsize+=10;
        q=new int[maxsize];
        while(i<s){
            enqueue(temp[i]);
            i++;
        }
        cout<<"Now max size of queue is : "<<maxsize<<endl;
        delete []temp;
    }
    bool empty()
    {
        return !size();
    }
    int size()
    {
        return re-fr;
    }
    int Front()
    {
        if(!empty())
            return q[fr];
        else{
            cout<<"queue is empty"<<endl;
            return -9999999;
        }
    }
    int rear()
    {
        if(!empty())
            return q[re-1];
        else{
            cout<<"queue is empty"<<endl;
            return -9999999;
        }

    }
    void enqueue(int x)
    {
        if(size()==maxsize)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        q[re++]=x;
    }
    void dequeue()
    {
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        fr++;
        cout<<"dequeue is successful"<<endl;
    }
    void exit()
    {
    while(!empty()){
        cout << Front()<<endl;
        dequeue();
    }
    }
};



int main()
{
    cout<<"Enter a number(1 or 2)"<<endl;
    cout<<"1 : Stack"<<endl;
    cout<<"2 : Queue"<<endl;
    int k;
    cin>>k;


    if(k==1){
    cout<<"For the stack"<<endl;
    STACK stk;
    int c;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Push an element" <<"        " << "4: Top" <<endl;
    cout << "2: Pop" <<"                    " << "5: Size" <<endl;
    cout << "3: Empty"<<"                  "  << "6: Exit"<<endl;
    cin >>c;
    switch(c)
    {
    case 1:
        cout<<"Enter the element : ";
        int x;
        cin>>x;
        if(stk.size()==stk.Maxsize())
        {
            cout<<"Dynamically Allocating memory for 10 more elements.............."<<endl;
            stk.resize();
        }
        stk.push(x);
        break;
    case 2:
        stk.pop();
        break;
    case 3:
        if(stk.empty()) cout<<"stack is empty"<<endl;
        else cout<<"stack is not empty"<<endl;
        break;
    case 4:
        cout<<"Top : "<<stk.top()<<endl;
        break;
    case 5:
        cout << "The current size of array is : " << stk.size() << endl;
       break;
    case 6:
       stk.exit();
        return 0;
    }
    }
    }



    else if(k==2){
        cout<<"For the Queue"<<endl;
        Queue q;
        int c;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Enqueue an element" <<"        " << "5: Front" <<endl;
    cout << "2: Dequeue" <<"                   " << "6: Size" <<endl;
    cout << "3: Empty"<<"                     "  << "7: Exit"<<endl;
    cout<<  "4: Rear"<<endl;
    cin >>c;
    switch(c)
    {
    case 1:
        cout<<"Enter the element : ";
        int x;
        cin>>x;
        if(q.size()==q.Maxsize())
        {
            cout<<"Dynamically Allocating memory for 10 more elements.............."<<endl;
            q.resize();
        }
        q.enqueue(x);
        break;
    case 2:
        q.dequeue();
        break;
    case 3:
        if(q.empty()) cout<<"queue is empty"<<endl;
        else cout<<"queue is not empty"<<endl;
        break;
    case 4:
        cout<<"Rear : "<<q.rear()<<endl;
        break;
    case 5:
        cout<<"Front : "<<q.Front()<<endl;
        break;
    case 6:
        cout << "The current size of array is : " << q.size() << endl;
       break;
    case 7:
       q.exit();
        return 0;
    }
    }
    }
    else{
        cout<<"wrong number !!"<<endl;
    }
}

