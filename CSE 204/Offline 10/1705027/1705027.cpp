#include<iostream>
#include<string>
#include<cstring>

#define diagonal 1
#define left 2
#define up 3
using namespace std;


int lengthLCS(int **v,int **m,string x,string y)
{
    int lx,ly;
    lx=x.length();
    ly=y.length();
    for(int i=0;i<=lx;i++)
        v[i][0]=0;
    for(int i=0;i<=ly;i++)
        v[0][i]=0;
    for(int i=1;i<=lx;i++)
    {
        for(int j=1;j<=ly;j++)
        {
            if(x[i-1]==y[j-1])
            {
                v[i][j]=v[i-1][j-1]+1;
                m[i][j]=diagonal;
            }
            else
            {
                if(v[i][j-1]>v[i-1][j])
                {
                    v[i][j]=v[i][j-1];
                    m[i][j]=left;
                }
                else if(v[i][j-1]<=v[i-1][j])
                {
                    v[i][j]=v[i-1][j];
                    m[i][j]=up;
                }
            }
        }
    }

    return v[lx][ly];

}

void printLCS(int **m,string s,int i,int j)
{
    if(i==0 || j==0)
        return;

    if(m[i][j]==diagonal)
    {
        printLCS(m,s,i-1,j-1);
        cout<<s[i-1];
    }
    else if(m[i][j]==left)
    {
        printLCS(m,s,i,j-1);
    }
    else{
        printLCS(m,s,i-1,j);
    }
}

int main()
{
    string s1,s2;
    int i;
    //cout<<"Enter the first string : ";
    cin>>s1;
    //cout<<"Enter the second string : ";
    cin>>s2;
    int x=s1.length();
    int y=s2.length();
    int **v;
    int **m;
    v=new int *[x+1];
    m=new int *[x+1];
    for(i=0;i<=x;i++)
    {
        v[i]=new int[y+1];
        m[i]=new int[y+1];
    }
    lengthLCS(v,m,s1,s2);
    //cout<<"Length of LCS : "<<v[x][y]<<endl;
    //cout<<"LCS : ";
    printLCS(m,s1,x,y);

}
