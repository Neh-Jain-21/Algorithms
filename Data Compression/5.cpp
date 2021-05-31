// Write a code to derive a Golomb Code for some value of n and m.
#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

int findGolomb(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return 1 + findGolomb(n - findGolomb(findGolomb(n - 1)));
}

void printGolomb(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << findGolomb(i) << " ";
    }
}

int main()
{
    int n = 9;
    printGolomb(n);
    getch();
    return 0;
}