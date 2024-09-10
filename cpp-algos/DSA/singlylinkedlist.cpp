#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class Node
{
public:
    int info;
    Node *Link;
};
class List:public Node
{
    Node *L;
public:
    List()
    {
        L=NULL;
    }
    void Insert(int data);
    void Insend(int data);
    void Insat(int key,int data);
    void display();
    void Reverse();
    void Delete(int key);
    void Search();
    void Count();
    void Sort();
};
void List::Insert(int data)
{
    Node *x;
    x=new Node;
    x->info=data;
    x->Link=NULL;
    if(L==NULL)
    {
        L=x;
    }
}
void List::Insend(int data)
{
    Node *x;
    x = new Node;
    x->info=data;
    x->Link=NULL;
    if(L==NULL)
    {
        L=x;
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
void List::Reverse()
{
    Node *p;
    p=R;
    cout <<"L->";
    while(p!=NULL)
    {
        cout << p->info <<"\t";
        p=p->Lptr;
    }
    cout <<"<-R"<< endl;
}
void List::Search()
{
    int key,i=1;
    cout <<"Enter Key:";
    cin >> key;
    Node *OLD;
    OLD=L;
    if(OLD==NULL)
    {
        cout <<"Key not found";
        getch();
        return;
    }
    while(OLD->info!=key)
    {
        OLD=OLD->Rptr;
        i++;
    }
    cout<<"Key is at="<<i<<endl;
}
void List::Sort()
{
    Node *x,*y;
    int temp;
    for(x=L;x!=NULL;x=x->Rptr)
    {
        for(y=x->Rptr;y!=NULL;y=y->Rptr)
        {
            if(x->info>y->info)
            {
                temp=x->info;
                x->info=y->info;
                y->info=temp;
            }
        }
    }
    cout<<"Sorted List is:"<<endl;
}
void List::Count()
{
    int i=0;
    Node *x;
    if(L==NULL)
    {
        cout <<"List is empty";
        getch();
        return;
    }
    x=L;
    while(x!=NULL)
    {
        x=x->Rptr;
        i++;
    }
    cout<<"No. of Elements="<<i<<endl;
}
void List::display()
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
int main()
{
    List L1;
    int choice,key,data;
    cout << "1. Insert"<<endl;
    cout << "2. Insend"<<endl;
    cout << "3. Insat"<<endl;
    cout << "4. Delete"<<endl;
    cout << "5. Reverse"<<endl;
    cout << "6. Search"<<endl;
    cout << "7. Sort"<<endl;
    cout << "8. Count"<<endl;
    cout << "9. Display"<<endl;
    cout << "10. Exit"<<endl;
    while(choice!=10)
    {
        L1.display();
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
                cout<<"Reversed List is"<<endl;
                L1.Reverse();
                break;
            case 6:
                L1.Search();
                break;
            case 7:
                L1.Sort();
                break;
            case 8:
                L1.Count();
                break;
            case 9:
                L1.display();
                break;
            case 10:
                break;
            default:
                cout << "Invalid choice";
        }

    }
}

