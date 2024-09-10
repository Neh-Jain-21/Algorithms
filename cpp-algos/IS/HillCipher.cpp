#include <iostream>
#include<conio.h>
using namespace std; 
  
void getKeyMatrix(string key, int keyMatrix[][2]) 
{ 
    int k = 0; 
    for (int i = 0; i < 2; i++)  
    { 
        for (int j = 0; j < 2; j++)  
        { 
            keyMatrix[i][j] = (key[k]) % 65;
            k++; 
        } 
    } 
} 
  
void encrypt(int cipherMatrix[][1], int keyMatrix[][2], int messageVector[][1])
{ 
    int x, i, j; 
    for (i = 0; i < 2; i++)
    { 
        for (j = 0; j < 1; j++) 
        { 
            cipherMatrix[i][j] = 0; 
            for (x = 0; x < 2; x++) 
            {
                cipherMatrix[i][j] += (keyMatrix[i][x] * messageVector[x][j]); 
            } 
            // cout<<cipherMatrix[i][j]<<" ";
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
        // cout<<endl;
    } 
} 
  
void HillCipher(string message, string key) 
{
    int keyMatrix[2][2], messageVector[2][1], cipherMatrix[2][1],L=0;
    string CipherText;

    getKeyMatrix(key, keyMatrix); 
    
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++) 
        {
            messageVector[i][0] = (message[L]) % 65;
            L++;
            // cout<<messageVector[i][0]<<" ";
        } 
        encrypt(cipherMatrix, keyMatrix, messageVector); 
        for (int k = 0; k < 2; k++) 
        {
            CipherText += cipherMatrix[k][0] + 65; 
        }
    }
    cout << "Ciphertext:" << CipherText;
} 
  
int main() 
{ 
    string message,key; 
    cout<<"Enter Message(Length=6):-"; 
    cin>>message;
    cout<<"Enter Key(Length=4):-";
    cin>>key;

    HillCipher(message, key); 

    getch();
    return 0; 
} 