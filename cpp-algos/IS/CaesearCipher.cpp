#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std; 
  
string encrypt(string text, int s) 
{ 
    string result = ""; 
    for (int i=0;i<text.length();i++) 
    { 
        if(isupper(text[i]))
        {
            result=result+char(int(text[i]+s-65)%26+65); 
        }
        else
        {
            result=result+char(int(text[i]+s-97)%26+97);
        }
    } 
    return result; 
}
string decrypt(string text,int s)
{
    string result = ""; 
    for (int i=0;i<text.length();i++) 
    { 
        if(isupper(text[i]))
        {
            result=result+char(int(text[i]-s-65)%26+65); 
        }
        else
        {
            result=result+char(int(text[i]-s-97)%26+97);
        }
    } 
    return result;
} 
int main() 
{ 
    string text; 
    int k,choice;
    while (choice!=3)
    {
        cout<<"Caeser Cypher Encryption and Decryption"<<endl;
        cout<<"----------"<<endl;
        cout<<"1. Encrypt"<<endl;
        cout<<"2. Decrypt"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"----------"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice;
        if (choice==1)
        {
            cout<<"Enter Text: ";
            cin>>text;
            cout<<"Enter Key: ";
            cin>>k;
            cout<<"Cipher Text: "<<encrypt(text,k)<<endl;
            getch();
            system("CLS");
        }
        else if (choice==2)
        {
            cout<<"Enter Text: ";
            cin>>text;
            cout<<"Enter Key: ";
            cin>>k;
            cout<<"Cipher Text: "<<decrypt(text,k)<<endl; 
            getch();
            system("CLS");
        }
        else if(choice==3)
        {

        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }
    }
}