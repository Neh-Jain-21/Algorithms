#include<iostream>
using namespace std;

class Queue
{
    int Q[5],Front=-1,Rear=-1,New;
public:
    void Enqueue(int);
    void Dequeue();
    void Display();
    int Search();
    int Change();
};
void Queue::Enqueue(int value)
{
   if((Front==0 && Rear==4) || Front==Rear+1)
   {
       cout<<"Overflow"<<endl;
   }
   else
   {
       if(Rear==4 && Front!=0)
        Rear=-1;
       Q[++Rear]=value;
       cout<<"Inserted"<<endl;
       if(Front==-1)
        Front=0;
   }
}
void Queue::Dequeue()
{
    if(Front==-1 && Rear==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        cout<<"Deleted Element="<<Q[Front++]<<endl;
        if(Front==5)
            Front=0;
        if(Front-1==Rear)
            Front=Rear=-1;
    }
}
void Queue::Display()
{
    if(Front==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        int i=Front;
        cout<<"Elements are:"<<endl;
        if(Front<=Rear)
        {
            while(i<=Rear)
            {
                cout<<Q[i]<<endl;
                i++;
            }
        }
        else
        {
            while(i<=4)
            {
                cout<<Q[i]<<endl;
                i++;
            }
            i=0;
            while(i<=Rear)
            {
                cout<<Q[i]<<endl;
                i++;
            }
        }
        cout<<"Front at "<<Front<<" and Rear at "<<Rear<<endl;
    }
}
int Queue::Search()
{
    if(Rear>4)
    {
        cout<<"Greater Than Size"<<endl;
    }
    else
    {
        cout<<"Enter Search Index=";
        cin>>Rear;
        cout<<Q[Rear]<<" at index "<<Rear<<endl;
    }
}
int Queue::Change()
{
    int j=Front;
    cout<<"Enter Index to Change=";
    cin>>j;
    if(j>4)
    {
        cout<<"Greater Than Size"<<endl;
    }
    else
    {
        cout<<"Enter New Data=";
        cin>>New;
        int temp;
        temp=Q[j];
        Q[j]=New;
        New=temp;
    }
}
int main()
{
    int s,value;
    Queue Q1;
    cout<<"1:Enqueue"<<endl;
    cout<<"2:Dequeue"<<endl;
    cout<<"3:Search"<<endl;
    cout<<"4:Change"<<endl;
    cout<<"5:Display"<<endl;
    cout<<"6:Exit"<<endl;
    while(s!=6)
    {
        cout<<"Enter choice:";
        cin>>s;
        switch(s)
        {
            case 1:
                cout<<"Enter Value to Insert=";
                cin>>value;
                Q1.Enqueue(value);
                break;
            case 2:
                Q1.Dequeue();
                break;
            case 3:
                Q1.Search();
                break;
            case 4:
                Q1.Change();
                break;
            case 5:
                Q1.Display();
                break;
        }
    }
}
