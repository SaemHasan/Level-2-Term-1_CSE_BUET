#include<iostream>
using namespace std;
struct node
    {
        int data;
        node *left,*right;
    };
int a[1000];
int a1[1000];
int idx=0;
int idx1=0;
class BST
{
    node *root;

    node* Search(node *t,int x)
    {
        if(t==NULL) return NULL;
        if(x < t->data)
            return Search(t->left,x);
        if(x > t->data)
            return Search(t->right,x);
        return t;
    }


    node* bstMin(node *t)
    {
        if(t==NULL) return NULL;
        else if(t->left!=NULL)
            return bstMin(t->left);
        return t;
    }

    node* bstMax(node *t)
    {
        if(t==NULL) return NULL;
        else if(t->right!=NULL)
            return bstMax(t->right);
        return t;
    }

    node* Delete(int x,node *t)
    {
        node *temp;
        if(t==NULL) return NULL;
        else if(x < t->data)
        {
            t->left=Delete(x,t->left);
        }
        else if(x > t->data)
        {
            t->right=Delete(x,t->right);
        }
        else if(t->left && t->right)
        {
            temp=bstMin(t->right);
            t->data=temp->data;
            t->right=Delete(t->data,t->right);

        }
        else{
            temp=t;
            if(t->left == NULL)
            {
                t=t->right;
            }
            else if(t->right == NULL)
            {
                t=t->left;
            }
            delete temp;
        }
        return t;
    }

    void Inorder(node* t,int &i)
    {
        if(t == NULL)
            return;
        Inorder(t->left,i);
        cout << t->data << " ";
        a[i++]=t->data;
        Inorder(t->right,i);
    }

    void Preorder(node *t,int &i)
    {
        if(t==NULL) return;
        cout<<t->data <<" ";
        a1[i++]=t->data;
        Preorder(t->left,i);
        Preorder(t->right,i);
    }


public:
    BST()
    {
        root=NULL;
    }

    node* Insert(int x,node *t)
    {
        if(t==NULL)
        {
            t=new node;
            t->data=x;
            t->left=t->right=NULL;
        }
        else if(x < t->data)
            t->left=Insert(x,t->left);
        else if(x > t->data)
            t->right=Insert(x,t->right);
        return t;
    }

    bool Search(int x)
    {
        node *tem = Search(root, x);
        if(tem==NULL) return false;
        return true;
    }

    void Insert(int x)
    {
        root = Insert(x, root);
        //cout<<"root :"<<root->data<<endl;
    }

    void Delete(int x)
    {
        if(root==NULL)
        {
            cout<<"Binary Search Tree is empty"<<endl;
            return;
        }
        root = Delete(x, root);
        if(root!=NULL)
       cout<<"root :"<<root->data<<endl;
    }

    void PreOrder()
    {
        if(root!=NULL){
                cout<<"Pre Order :"<<endl;
                Preorder(root,idx1);
                cout<<endl;
        }
    }

    void InOrder()
    {
        if(root!=NULL){
                cout<<"In Order :"<<endl;
                Inorder(root,idx);
                cout<<endl;
                /*for(int i=0;i<idx;i++)
                cout<<a[i]<<" ";
                cout<<endl;*/
        }

    }

};
void rightInsert(BST t1,int i,int h);
void leftInsert(BST t1,int i,int l)
    {
    int m=(i-1)/2;
    if(m<0) return;

    t1.Insert(a[m]);
    leftInsert(t1,m,0);
    rightInsert(t1,m,i);
    }

void rightInsert(BST t1,int i,int h)
{
    int m=i+(h-m)/2;
    if(m>=h) return;
    t1.Insert(a[m]);
    leftInsert(t1,m,i);
    rightInsert(t1,m,idx);
}
void INSERT(BST  t,int low,int high)
{
    if(low>high) return;

    /*if(low==high)
    {
        t.Insert(a[low]);
    }*/

    int mid=(low-high)/2;
    if(mid<0 || mid>=idx) return;
    t.Insert(a[mid]);
    INSERT(t,low,mid);
    INSERT(t,mid,high);
}
void makeTree()
{
    BST t1;
    /*for(int i=0;i<idx1;i++)
        cout<<a1[i]<<" ";*/

    //t1.constructTree(a1,idx1);
    int mid=0;
            mid=(idx+1)/2;
            t1.Insert(a[mid]);
            //leftInsert(t1,mid,0);
            //ightInsert(t1,mid,idx);
            INSERT(t1,0,mid-1);
            INSERT(t1,mid+1,idx-1);
    //t1.InOrder();
    t1.PreOrder();
}

int main()
{
    BST t;
    int c;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Insert an element" <<"        " << "4: In Order" <<endl;
    cout << "2: Delete" <<"                   " << "5: Pre Order" <<endl;
    cout << "3: Search"<<"                   "<<"6: Make tree"<<endl;
    cin >>c;
    switch(c)
    {
    case 1:
        cout<<"Enter the element : ";
        int x;
        cin>>x;
        if(t.Search(x)) cout<<"element is already in the tree"<<endl;
        else
                t.Insert(x);
        break;
    case 2:
        int x1;
        cout<<"Enter  the element you want to delete : ";
        cin>>x1;
        if(!t.Search(x1)) cout<<"element is not in the tree"<<endl;
        else{
                t.Delete(x1);
                cout<<"delete successful "<<endl;
        }
        break;
    case 3:
        int x2;
        cout<<"Enter  the element you want to Search : ";
        cin>>x2;
        if(!t.Search(x2)) cout<<"element is not in the tree"<<endl;
        else cout<<"element is in the tree!"<<endl;
        break;
    case 4:
        t.InOrder();
       break;
    case 5:
        t.PreOrder();
        break;
    case 6:
        t.InOrder();
        t.PreOrder();
        makeTree();
    }
    }
}

