#include<iostream>
using namespace std;

class Queue
{
    int Rear=0;
    int Front=0;
    int Size=5,Q[5],Y,i,New;
public:
    int Enqueue();
    void display();
    void Dequeue();
    int Search();
    int Change();
};
int Queue::Enqueue()
{
    if(Rear>=Size)
    {
        cout<<"Queue Overflow";
    }
    else
    {
        for(Rear=1;Rear<=6;Rear++)
        {
            cout<<"Enter Data "<<Rear<<"=";
            cin>>Q[Rear];
        }
    }
    if(Front==0)
    {
        Front=1;
    }

}
void Queue::Dequeue()
{
    if(Front==0)
    {
        cout<<"Queue Underflow"<<endl;
    }
    else
    {
        int Temp;
        Temp=Q[Front];
        cout<<"Deleted "<<Q[Front]<<endl;
        Front++;
    }
}
int Queue::Search()
{
    if(Rear>Size)
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
    cout<<"Enter Index to Change=";
    cin>>Rear;
    if(Rear>Size)
    {
        cout<<"Greater Than Size"<<endl;
    }
    else
    {
        cout<<"Enter New Data=";
        cin>>New;
        int temp;
        temp=Q[Rear];
        Q[Rear]=New;
        New=temp;
    }
}
void Queue::display()
{
    for(Rear=Front;Rear<=6;Rear++)
    {
        cout<<"Data "<<Rear<<" ="<<Q[Rear]<<endl;
    }
    cout<<"Front at "<<Front<<" and Rear at "<<Rear<<endl;
}
main()
{
    int s;
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
                Q1.Enqueue();
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
                Q1.display();
                break;
        }
    }
}
