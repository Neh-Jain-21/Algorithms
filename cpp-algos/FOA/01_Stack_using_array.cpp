#include<iostream>
using namespace std;

class stacks
{
public:
    int size,j,top=-1;
    stacks()
    {
        int size;
        cout<<"Enter Size of New Stack=";
        cin>>size;
        cout<<"New Stack Created"<<endl;
        this->size=size;
    }
    int* q=new int[size];
    void push()
    {
        int x;
        if(top>=size-1)
        {
            cout<<"STACK is OVERFLOW"<<endl;
        }
        else
        {
            cout<<"Enter Data:";
            cin>>x;
            top++;
            q[top]=x;
            display();
        }
    }
    void pop()
    {
        int temp;
        if(top<=-1)
        {
            cout<<"STACK is Underflow"<<endl;
        }
        else
        {
            temp=q[size];
            top--;
            display();
        }
    }
    void display()
    {
        if(top<0)
        {
            cout<<"STACK is Underflow"<<endl;
        }
        else
        {
            for(j=top;j>=0;j--)
            {
                cout<<q[j]<<"\n";
            }
        }
    }
    ~stacks()
    {
        cout<<"Old Stack Destroyed"<<endl<<endl;
    }
};
int main()
{
    int size,s;
Start:
    stacks s1=stacks();
    cout<<"-------------------"<<endl;
    cout<<"1: Push"<<endl;
    cout<<"2: Pop"<<endl;
    cout<<"3: Display"<<endl;
    cout<<"4: Create New Stack"<<endl;
    cout<<"5: Exit"<<endl;
    cout<<"-------------------"<<endl;
    while(s!=5)
    {
        cout<<"Enter choice:";
        cin>>s;
        switch(s)
        {
            case 1:
                s1.push();
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                goto Start;
        }
    }
}
