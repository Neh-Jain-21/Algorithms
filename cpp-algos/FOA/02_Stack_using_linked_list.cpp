#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Node
{
public:
    int info;
    Node* link;
};
class List:public Node
{
public:
    Node* top=NULL;
    void push(int data)
    {
        Node* x;
        x = new Node;
        x->info=data;
        x->link=top;
        top=x;
    }
    void display()
    {
        Node* p;
        if(top==NULL)
        {
            cout<<"Stack Underflow!"<<endl;
        }
        else
        {
            p=top;
            while(p!=NULL)
            {
                cout << p->info <<endl;
                p=p->link;
            }
        }
    }
    void Delete()
    {
        Node* old;
        if(top==NULL)
        {

        }
        else
        {
            old=top;
            top=top->link;
            old->link=NULL;
            delete old;
        }
    }
};
int main()
{
    List L1;
    int choice,data;
    while(choice!=3)
    {
        system("cls");
        L1.display();
        cout << "-----------------------\n";
        cout << "1. Insert"<<endl;
        cout << "2. Delete"<<endl;
        cout << "3. Exit"<<endl;
        cout << "-----------------------\n";
        cout <<"Choice:";
        cin >>choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value:";
                cin >> data;
                L1.push(data);
                break;
            case 2:
                L1.Delete();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice";
                getch();
        }
    }
}
