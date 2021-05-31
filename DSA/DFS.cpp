#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Search
{
    int adj[10][10],mark[10],n;
public:
    void DFS(int);
    void create_Graph();
    void DF_Search();
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
void Search::DF_Search()
{
    int i;
    for(i=0;i<n;i++)
    {
        mark[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(mark[i]!=0)
        {
            DFS(i);
        }
    }
}
void Search::DFS(int i)
{
    int w;
    cout<<"\ni";
    mark[i]=1;
    cout<<"i";
    for(w=0;w<n;w++)
    {
        if(adj[i][w]==1 && mark[w]!=1)
        {
            DFS(w);
        }
    }
}
int main()
{
    Search S;
    S.create_Graph();
    S.DF_Search();
}
