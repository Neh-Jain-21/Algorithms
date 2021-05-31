#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define Max 100
#define not_visited 1
#define visited 2
using namespace std;

class Search
{
    int n,adj[Max][Max],Mark[Max],Queue[Max],Front=0,Rear=0,vertex;
public:
    void create_Graph();
    void BF_Search();
    void BFS(int v);
    void Enqueue(int vertex);
    int Dequeue();
    int isEmpty_Queue();
};
void Search::create_Graph()
{
    int Count,Max_edge,Origin,destin;
    cout<<"Enter No. of vertices:";
    cin>>n;
    Max_edge=n*(n-1);
    for(Count=1;Count<=Max_edge;Count++)
    {
        cout<<"Enter edge "<<Count <<"(-1 -1 to quit)";
        cin>>Origin>>destin;
        if((Origin==-1) && (destin==-1))
        {
            break;
        }
        else if((Origin>=n) || destin>=n || Origin<0 || destin<0)
        {
            cout<<"invalid edge\n";
            Count--;
        }
        else
        {
            adj[Origin][destin]=1;
        }
    }
}
void Search::BF_Search()
{
    int v,i;
    for(v=0;v<n;v++)
    {
        Mark[v]=not_visited;
    }
    cout<<"Enter start vertex for BFS:";
    cin>>i;
    for(v=i;v<n;v++)
    {
        if(Mark[v]!=visited)
        {
            BFS(v);
        }
    }
}
void Search::BFS(int v)
{
    int w,u;
    Mark[v]=visited;
    Enqueue(v);
    while(Front!=0 || Front!=Rear)
    {
        v=Queue[Front];
        cout<<v;
        Dequeue();
        for(w=0;w<n;w++)
        {
            if(adj[v][w]==1 && Mark[w]!=visited)
            {
                Mark[w]=visited;
            }
        }
        Enqueue(w);
    }
    cout<<"\n";
}
void Search::Enqueue(int vertex)
{
    if(Rear>=n)
    {
        cout<<"Queue Overflow";
    }
    else
    {
        Queue[Rear]=vertex;
        Rear++;
    }
    if(Front==0)
    {
        Front=1;
    }
}
int Search::Dequeue()
{
    if(Front==0)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        int Temp;
        Temp=Queue[Front];
        Front++;
    }
}
int main()
{
    Search S;
    S.create_Graph();
    S.BF_Search();
    return 0;
}
