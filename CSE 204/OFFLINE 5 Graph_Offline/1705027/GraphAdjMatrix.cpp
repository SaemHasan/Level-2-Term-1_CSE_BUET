#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

using namespace std;

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;  // circular queue implementation
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************


//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	int ** matrix ; //adjacency matrix to store the graph
    int *color;
	int *dist;
	int *parent;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u,bool out=true);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ; //set direction of the graph
    color=0;
    dist=0;
    parent=0;
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	//allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; //initialize the matrix cells to 0
    }
    color=new int[nVertices];
    dist=new int[nVertices];
    parent=new int[nVertices];
}

void Graph::addEdge(int u, int v)
{
    //write your code here
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) {
            cout<<"vertex out of range"<<endl;
            return; //vertex out of range
    }
    matrix[u][v] = 1;
    if(!directed) matrix[v][u] = 1;
    cout<<"Added Successfully"<<endl;
}

void Graph::removeEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) {
        cout<<"vertex out of range"<<endl;
            return;
    }
    if(isEdge(u,v)){
        matrix[u][v]=0;
    if(!directed) matrix[v][u]=0;
    cout<<"Delete Successfully"<<endl;
    }
    else
    {
        cout<<"there is no edge to delete"<<endl;
    }
    //write this function
}

bool Graph::isEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) {
            cout<<"vertex out of range"<<endl;
            return false;
    }
    if(matrix[u][v]==1)
                return true;
    return false;
    //returns true if (u,v) is an edge, otherwise should return false
}

int Graph::getDegree(int u,bool out)
{
    if(u<0 || u>=nVertices) {
            cout<<"vertex out of range"<<endl;
            return NULL_VALUE;
    }
    if(out){
        int c=0;
     for(int i=0;i<nVertices;i++)
     {
         if(isEdge(u,i))
            c++;
     }
    return c;
    }
    if(!out){
        int c=0;
        for(int i=0;i<nVertices;i++)
        {
            if(isEdge(i,u))
                c++;
        }
    return c;
    }
    //returns the degree of vertex u
}

void Graph::printAdjVertices(int u)
{
        if(u<0 || u>=nVertices) {
        cout<<"vertex out of range"<<endl;
        return;
    }
    int idx=-1;
    for(int i=0;i<nVertices;i++){
        if(matrix[u][i]==1){
            idx=1;
            cout<<"Adjacent Vertex :"<<i<<endl;
        }
    }
    if(idx==-1) cout<<"there is no adjacent vertex of "<<u<<endl;
    //prints all adjacent vertices of a vertex u
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) {
            cout<<"vertex out of range"<<endl;
            return false;
    }
    for(int i=0;i<nVertices;i++)
    {
        if(matrix[u][i]==1 && matrix[v][i]==1)
            return true;
    }
    return false;
    //returns true if vertices u and v have common adjacent vertices

}

void Graph::bfs(int source)
{
        if(source<0 || source>=nVertices) {
        cout<<"vertex out of range"<<endl;
        return;
    }

    for(int i=0;i<nVertices;i++)
    {
        color[i]=WHITE;
    }
    Queue q;
    q.enqueue(source);
    color[source]=GREY;
    dist[source]=0;
    parent[source]=source;
    while(!q.empty())
    {
        int u=q.dequeue();

        for(int i=0;i<nVertices;i++){
                if(matrix[u][i]==1){
                int v=i;
                if(color[v]==WHITE)
                {
                    cout<<v<<" ";
                    color[v]=GREY;
                    dist[v]=dist[u]+1;
                    parent[v]=u;
                    q.enqueue(v);
                }
        }
        }
        color[u]=BLACK;
    }
    cout<<endl;
    //write this function

}

int Graph::getDist(int u, int v)
{
        if(u<0 || v<0 || u>=nVertices || v>=nVertices)
    {
        cout<<"vertex out of range"<<endl;
        return INFINITY;
    }
    bfs(u);
    if(color[v]==WHITE)
    {
        cout<<"there is no path between "<<u <<" and "<<v<<endl;
        return INFINITY;
    }
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    return dist[v];
}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    for(int i = 0; i < nVertices; ++i) {
        delete []matrix[i];
        matrix[i]=0;
    }
    delete []matrix;
    matrix=0;
    if(color) delete []color;
    if(dist) delete []dist;
    if(parent) delete[]parent;
    color=0;
    dist=0;
    parent=0;
    //write your destructor here
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    int choice;
    bool dir;
    printf("Enter your choice:\n");
    printf("1. directed graph   2. undirected graph\n");
    scanf("%d",&choice);
    if(choice == 1)dir = true;
    else if(choice == 2)dir = false;

    Graph g(dir);
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
    cout << "Enter a number : " <<endl;
    cout << "1: Add edge" <<"        " << "6: Get Degree" <<endl;
    cout << "2: Delete edge" <<"     " << "7: Print Adj Vertexes" <<endl;
    cout << "3: Is Edge"<<"         "<<"8: hasCommonAdjacent"<<endl;
    cout << "4: BFS" <<"             " << "9: Print Graph" <<endl;
    cout << "5: Get Distance" <<"    " << "10: Exit" <<endl;

        int ch;
        int u, v;
        scanf("%d",&ch);
        if(ch==1)
        {
            cout<<"Enter the first vertex : "<<endl;;
            cin>>u;
            cout<<"Enter the Second vertex : "<<endl;
            cin>>v;
            if(!g.isEdge(u,v))
                g.addEdge(u, v);
            else
                cout<<"there is already an edge between "<<u<<" and "<<v<<endl;
        }
        else if(ch==2)
        {
            cout<<"Enter the first vertex : "<<endl;;
            cin>>u;
            cout<<"Enter the Second vertex : "<<endl;
            cin>>v;
            g.removeEdge(u,v);
        }
        else if(ch==3)
        {
            cout<<"Enter the first vertex : "<<endl;;
            cin>>u;
            cout<<"Enter the Second vertex : "<<endl;
            cin>>v;
        if(g.isEdge(u,v))
            cout<<"there is a edge between "<<u<<" and "<<v<<endl;
        else
            cout<<"there is no edge"<<endl;
        }
        else if(ch==4)
        {
        int s;
        cout<<"Enter the source : "<<endl;
        cin>>s;
        g.bfs(s);
        }
        else if(ch==5)
        {
        cout<<"Enter the first vertex : "<<endl;;
        cin>>u;
        cout<<"Enter the Second vertex : "<<endl;
        cin>>v;
        int d;
        d=g.getDist(u,v);
        if(d!=INFINITY) cout<<"the distance between "<<u<<" and "<<v <<" is : "<<d<<endl;
        }
        else if(ch==6)
        {
        cout<<"Enter the vertex :"<<endl;
        cin>>v;
        int d;
        if(dir!=true)  {
                d=g.getDegree(v);
        }
        else{
            cout<<"Enter the choice"<<endl;
            cout<<"1. out degree"<<endl;
            cout<<"2. in degree"<<endl;
            int c;
            cin>>c;
            if(c==2) d=g.getDegree(v,false);
            else d=g.getDegree(v);
        }
        if(d==NULL_VALUE) cout<<"this vertex is not in the graph"<<endl;
        else
            cout<<"Degree : "<<d<<endl;
        }
        else if(ch==7)
        {
        cout<<"Enter the vertex : "<<endl;
        cin>>u;
        g.printAdjVertices(u);
        }
        else if(ch==8)
        {
            cout<<"Enter the first vertex : "<<endl;;
            cin>>u;
            cout<<"Enter the Second vertex : "<<endl;
            cin>>v;

            if(g.hasCommonAdjacent(u,v)) cout<<"Yes they have common adjacent"<<endl;
            else
                cout<<"there is no common adjacent"<<endl;
        }
        else if(ch==9)
        {
            g.printGraph();
        }
        else if(ch==10)
        {
            break;
        }
    }

}
