#include<iostream>
#include<string.h>
#define Size 100
using namespace std;

char stacks[Size];
int top=-1;
void push(char);
char pop();
void display();
int F(char);
int G(char);

void push(char x)
{
    if(top==Size-1)
    {
       cout<<"STACK OVERFLOW"<<endl;
    }
    else
    {
        top++;
        stacks[top]=x;
    }
}
char pop()
{
    char temp;
    if(top==-1)
    {
        cout<<"STACK is Underflow"<<endl;
    }
    else
    {
        temp=stacks[top];
        top--;
        return(temp);
    }
}
int F(char i)
{
    if(i=='+'||i=='-')
        return 1;
    else if(i=='*'||i=='/'||i=='%')
        return 3;
    else if(i=='^')
        return 6;
    else if(i>='a'&&i<='z'||i>='A'&&i<='Z')
        return 7;
    else if(i=='(')
        return 9;
    else if(i==')')
        return 0;
    else
        return -1;
}
int G(char i)
{
    if(i=='+'||i=='-')
        return 2;
    else if(i=='*'||i=='/'||i=='%')
        return 4;
    else if(i=='^')
        return 5;
    else if(i>='a'&&i<='z'||i>='A'&&i<='Z')
        return 8;
    else if(i=='(')
        return 0;
    else if(i==')')
        return 0;
    else
        return -1;
}
int main()
{
    char next[50],POSTFIX[50],temp;
    cout<<"ENTER INFIX STRING:";
    cin>>next;
    char b[10]=")";
    strcat(next,b);
    int i,j=0;
    for(i=0;next[i]!='\0';i++)
    {
        while(F(next[i])<G(stacks[top]))
        {
            temp=pop();
            if(temp=='(')
            {
                j=j;
            }
            else
            {
                POSTFIX[j]=temp;
                j++;
            }
        }
        if(F(next[i])>G(stacks[top]))
        {
            push(next[i]);
        }
        else
        {
            temp=pop();
            if(temp=='(')
            {
                j=j;
            }
            else
            {
                POSTFIX[j]=temp;
                j++;
            }
        }
    }
    POSTFIX[j]='\0';
    cout<<"POSTFIX STRING:"<<POSTFIX;
}
