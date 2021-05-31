// Write a program to display Self information and entropy of a paragraph taken as an input.
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    string str = "thisisttaatttotthet";
    cout << "String :- " << str << endl
         << endl;
    int len = str.length();
    char ch[len];
    int f[len], freq[len];
    float p[len], SI[len], PS[len], entropy = 0;

    //Frequency of characters
    for (int i = 0; i < len; i++)
    {
        f[i] = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
            {
                f[i]++;
                str[j] = '0';
            }
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != '0')
        {
            ch[count] = str[i];
            freq[count] = f[i];
            count++;
        }
    }

    //Probability of characters
    for (int i = 0; i < count; i++)
    {
        p[i] = float(freq[i]) / float(len);
        // cout<<p[i]<<endl;
    }

    //Finding Self Information
    for (int i = 0; i < count; i++)
    {
        SI[i] = log2(p[i]);
        // cout<<SI[i]<<endl;
    }

    //Finding P*S
    for (int i = 0; i < count; i++)
    {
        PS[i] = p[i] * SI[i];
        //cout<<PS[i]<<endl;
    }

    //Entropy
    for (int i = 0; i < count; i++)
    {
        entropy = entropy + PS[i];
    }

    //Printing
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|\tChar\t|\tFreq\t|\tProb\t|\tS.Info\t|\tP*S\t|" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << setprecision(2) << "|\t" << ch[i] << "\t|\t" << freq[i] << "\t|\t" << p[i] << "\t|\t" << SI[i] << "\t|\t" << PS[i] << "\t|";
        cout << endl;
    }
    cout << "|-------------------------------------------------------------------------------|" << endl;
    cout << "|\tTFreq\t=\t" << len << "\t|\t\t|\tEntropy\t=\t" << entropy << "\t|" << endl;
    cout << "|-------------------------------------------------------------------------------|" << endl;
    getch();
}