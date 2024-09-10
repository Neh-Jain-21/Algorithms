#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> Tree;
    int edge,n1,n2;

    cin>>edge;
    Tree.resize(edge);

    for (int i = 0; i < edge; i++)
    {
        cin>>n1>>n2;
        Tree[n1].push_back[n2];
    }
    
}