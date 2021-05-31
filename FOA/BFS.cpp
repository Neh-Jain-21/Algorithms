#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
# define MAXSIZE 50

int adj[MAXSIZE][MAXSIZE];
int visited[MAXSIZE];

struct st
{
    int front,rear;
    int queue[MAXSIZE];
};
struct st s;

int empty(void)
{
    if (s.front==s.rear+1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}

void insert(int item)
{
    s.rear=s.rear+1;
    s.queue[s.rear]=item;
    if (s.rear==1)
    {
        s.front=s.front+1;
    }
}

int del(void)
{
    int removed_item;
    if (empty()==1)
    {
        printf("\n\n\t\tQueue Empty!!\n");
        return 0;
    }
    else
    {
        removed_item=s.queue[s.front];
        s.front=s.front+1;
        return(removed_item);
    }
}

void BFS(int initial_node,int n)
{
    int u,i;
    u=initial_node;
    visited[initial_node]=1;
    cout<<"BFS traversal for given graph is : "<<initial_node<<" ";
    insert(initial_node);
    while (!empty())
    {
        u = del();
        for (i = 0; i < n; i++)
        {
            if ((adj[u][i]==1) && (visited[i]==0))
            {
                insert(i);
                visited[i]=1;
                cout<<i<<" ";
            }
        }
    }
}

int main()
{
    int n,i,j,parent,adj_parent,initial_node,c;
    char ans='y',ans1='y';

    cout<<"Enter total number elements in a Undirected Graph :";
    cin>>n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j]=0;
        }
    }
    for (c = 0; c < 50; c++)
    {
        visited[c]=0;
    }
    cout<<"Enter graph structure for BFS :-"<<endl;
    do
    {
        cout<<endl;
        cout<<"Enter parent node :";
        cin>>parent;
        do
        {
            cout<<"Enter adjacent node for "<<parent<<" :";
            cin>>adj_parent;
            adj[parent][adj_parent]=1;
            adj[adj_parent][parent]=1;

            cout<<"Continue to add adjacent node for "<<parent<<" ? y/n :";
            ans1=getche();
            cout<<endl;
        } 
        while (ans1=='y');
        cout<<"Continue to add graph node? y/n :";
        ans=getche();
        cout<<endl;
    } 
    while (ans=='y');
    cout<<endl;
    cout<<"Adjacency matrix for your graph is:-"<<endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <n ; j++)
        {
            cout<<adj[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Your Undirected Graph is:-"<<endl;

    for (i = 0; i < n; i++)
    {
        cout<<"Vertex "<<i<<" is connected to : ";
        for (j = 0; j < n; j++)
        {
            if (adj[i][j]==1)
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Enter the initial node for BFS traversal:";
    cin>>initial_node;
    BFS(initial_node,n);
}