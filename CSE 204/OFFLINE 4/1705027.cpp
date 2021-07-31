#include<iostream>
using namespace std;

class BST
{
    struct node
    {
        int data;
        node *left,*right;
    };

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

    void Inorder(node* t)
    {
        if(t == NULL)
            return;
        Inorder(t->left);
        cout << t->data << " ";
        Inorder(t->right);
    }

    void Preorder(node *t)
    {
        if(t==NULL) return;
        cout<<t->data <<" ";
        Preorder(t->left);
        Preorder(t->right);
    }
    void postorder(node *t)
    {
        if(t==NULL) return;
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<" ";
    }

public:
    BST()
    {
        root=NULL;
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
        cout<<"root :"<<root->data<<endl;
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
                Preorder(root);
                cout<<endl;
        }
        else
        {
            cout<<"Binary Search Tree is empty"<<endl;
        }
    }

    void InOrder()
    {
        if(root!=NULL){
                cout<<"In Order :"<<endl;
                Inorder(root);
                cout<<endl;
        }
        else
        {
            cout<<"Binary Search Tree is empty"<<endl;
        }
    }
    void postOrder()
    {
        if(root!=NULL){
                cout<<"post Order :"<<endl;
                postorder(root);
                cout<<endl;
        }
        else
        {
            cout<<"Binary Search Tree is empty"<<endl;
        }
    }
};


int main()
{
    BST t;
    int c;
    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Insert an element" <<"        " << "4: In Order" <<endl;
    cout << "2: Delete" <<"                   " << "5: Pre Order" <<endl;
    cout << "3: Search"<<"                   "<<"6: Exit"<<endl;
    cout<<"7: post order"<<endl;
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
        return 0;
    case 7:
        t.postOrder();
        break;
    }
    }
}
