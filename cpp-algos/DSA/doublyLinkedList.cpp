#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Node
{
public:
    int info;
    Node *Lptr;
    Node *Rptr;
};
class List:public Node
{
    Node *L,*R;
public:
    List()
    {
        L=NULL;
        R=NULL;
    }
    void Insert(int data);
    void Insend(int data);
    void Insat(int key,int data);
    void displayForward();
    void displayBackward();
    void Delete(int key);
};
void List::Insert(int data)
{
    Node *x;
    x = new Node;
    x->info=data;
    x->Lptr=NULL;
    x->Rptr=NULL;
    if(L==NULL)
    {
        L=R=x;
    }
    else
    {
        x->Rptr=L;
        L->Lptr=x;
        L=x;
    }
}
void List::Insend(int data)
{
    Node *x;
    x=new Node;
    x->info=data;
    x->Lptr=NULL;
    x->Rptr=NULL;
    if(R==NULL)
    {
        L=R=x;
    }
    else
    {
        x->Lptr=R;
        R->Rptr=x;
        R=x;
    }
}
void List::Insat(int key,int data)
{
    Node *M;
    M=L;
    while(M!=NULL && M->info!=key)
    {
        M=M->Rptr;
    }
    if(M==NULL)
    {
        cout << "Key not found";
        getch();
        return;
    }
    else
    {
        Node *x=new Node;
        x->Lptr=NULL;
        x->Rptr=NULL;
        x->info=data;
        if(M==L)
        {
            x->Rptr=L;
            L->Lptr=x;
            L=x;
        }
        else
        {
            x->Rptr=M;
            x->Lptr=M->Lptr;
            M->Lptr->Rptr=x;
            M->Lptr=x;
        }
    }
}
void List::displayForward()
{
    Node *p;
    p=L;
    cout << "L->";
    while(p!=NULL)
    {
        cout << p->info <<"\t";
        p=p->Rptr;
    }
    cout << "<-R";
    cout << endl;
}
void List::displayBackward()
{
    Node *p;
    p=R;
    cout <<"R->";
    while(p!=NULL)
    {
        cout << p->info <<"\t";
        p=p->Lptr;
    }
    cout <<"<-L"<< endl;
}
void List::Delete(int key)
{
    Node *OLD;
    if(L==NULL)
    {
        cout <<"List is empty";
        getch();
        return;
    }
    OLD=L;
    while(OLD!=NULL && OLD->info!=key)
    {
        OLD=OLD->Rptr;
    }
    if(OLD==NULL)
    {
        cout <<"Key not found";
        getch();
        return;
    }
    if(OLD==L && OLD==R)
    {
        delete OLD;
        L=R=NULL;
    }
    else if(OLD==L)
    {
        L=L->Rptr;
        L->Lptr=NULL;
        delete OLD;
    }
    else if(OLD==R)
    {
        R=R->Lptr;
        R->Rptr=NULL;
        delete OLD;
    }
    else
    {
        OLD->Lptr->Rptr=OLD->Rptr;
        OLD->Rptr->Lptr=OLD->Lptr;
        delete OLD;
    }
}
main()
{
    List L1;
    int choice,key,data;
    while(choice!=5)
    {
        system("cls");
        L1.displayForward();
        L1.displayBackward();
        cout << "1. Insert"<<endl;
        cout << "2. Insend"<<endl;
        cout << "3. Insat"<<endl;
        cout << "4. Delete"<<endl;
        cout << "5. Exit"<<endl;
        cout << "-----------------------\n";
        cout <<"Choice:";
        cin >>choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value:";
                cin >> data;
                L1.Insert(data);
                break;
            case 2:
                cout << "Enter Value:";
                cin >> data;
                L1.Insend(data);
                break;
            case 3:
                cout <<"Enter key:";
                cin >> key;
                cout << "Enter Data:";
                cin >> data;
                L1.Insat(key,data);
                break;
            case 4:
                cout <<"Enter Key:";
                cin >> key;
                L1.Delete(key);
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice";
        }
    }
}
