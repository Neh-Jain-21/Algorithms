// Implement encoder and decoder algorithm for Arithmetic coding.
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<conio.h>
using namespace std;

int main()
{
    string ustr, fstr = "nehhjain", str = "nehhjain";
    cout << "String :- " << str << endl
         << endl;
    int len = str.length();

    char ch[len];
    int freq[len], f[len];
    float p[len], cpr[len], newcpr[len + 1];

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
    }

    sort(p, p + count);

    for (int i = 0; i < count; i++)
    {
        // cout << p[i] << " ";
        cpr[i] = 0;
        for (int j = 0; j <= i; j++)
        {
            cpr[i] = cpr[i] + p[j];
        }
        // cout << cpr[i] << " ";
    }

    newcpr[0] = 0;
    for (int i = 0; i < count + 1; i++)
    {
        newcpr[i + 1] = cpr[i];
    }
    cout << endl;

    // Displaying the lookup table
    cout << "Table" << endl;
    for (int i = 0; i < count; i++)
    {
        // cout<<ch[i]<<" ";
        cout << newcpr[i] << "\t" << cpr[i] << setprecision(4) << fixed << endl;
        ustr += ch[i];
    }

    cout << endl
         << endl;

    // // Encoder Table

    float range, low = 0, high = 1;
    int pos;
    for (int i = 0; i < fstr.length(); i++)
    {
        for (int j = 0; j < ustr.length(); j++)
        {
            if (fstr[i] == ustr[j])
            {
                pos = j;
                cout << "pos = " << pos << endl;

                range = high - low;
                high = low + (range * newcpr[j + 1]);
                low = low + (range * newcpr[j]);
            }
        }
    }

    cout << endl
         << endl
         << low << endl;

    getch();
    return 0;
}