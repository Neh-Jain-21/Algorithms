// Write a program to generate Tunstall Code
#include <iostream>
#include <conio.h>
using namespace std;

class Helper
{
public:
    int calculateDi(int yi, int yibar)
    {
        return (yi - yibar);
    }

    int min(int a, int b)
    {
        int min = 0;
        if (a < b)
        {
            min = a;
        }
        else
        {
            min = b;
        }
        return min;
    }

    int yMax(int yi[], int n)
    {
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (yi[i] > max)
            {
                max = yi[i];
            }
        }
        return max;
    }

    int yMin(int yi[], int n)
    {
        int min = yi[0];
        for (int i = 0; i < n; i++)
        {
            if (yi[i] < min)
            {
                min = yi[i];
            }
        }
        return min;
    }

    string decToBinary(int n)
    {
        string final = "";
        int binaryNum[32];
        int i = 0;
        while (n > 0)
        {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            final = final + to_string(binaryNum[j]);
        }
        return final;
    }

    string getBinary(int n, int len)
    {
        string binaryValue = decToBinary(n);
        len = len - binaryValue.length();
        for (int i = 0; i < len; i++)
        {
            binaryValue = "0" + binaryValue;
        }
        return binaryValue;
    }

    string getUnaryCode(int n)
    {
        string unaryCode = "";
        for (int j = 0; j < n; j++)
        {
            unaryCode += "1";
        }
        unaryCode += "0";
        return unaryCode;
    }

    int calculateTi(int ymax, int ymin, int yibar)
    {
        return min(ymax - yibar, yibar - ymin);
    }
};

int main()
{
    int blockSize = 0, n = 0;
    cout << "Enter N : ";
    cin >> n;
    cout << "Enter Block Size : ";
    cin >> blockSize;
    int Yi[n], YiBar[n], Di[n], Ti[n], Xi[n];
    cout << "Enter " << n << " values Of Yi : ";

    for (int i = 0; i < n; i++)
    {
        cin >> Yi[i];
    }
    cout << "\n\nYi    :";
    for (int i = 0; i < n; i++)
    {
        cout << Yi[i] << "  ";
    }
    YiBar[0] = 0;

    cout << "\nYiBar :";
    cout << YiBar[0] << "  ";
    for (int i = 1; i < n; i++)
    {
        YiBar[i] = Yi[i - 1];
        if (YiBar[i] > 9)
        {
            cout << " " << YiBar[i] << " ";
        }
        else
        {
            cout << YiBar[i] << "  ";
        }
    }
    Helper helper;
    cout << "\nDi    :";
    for (int i = 0; i < n; i++)
    {
        Di[i] = helper.calculateDi(Yi[i], YiBar[i]);
        if (Di[i] > 9 && i != 0)
        {
            cout << " " << Di[i] << " ";
        }
        else
        {
            if (Di[i] < 0)
            {
                cout << "\b" << Di[i] << "   ";
            }
            else
            {
                cout << Di[i] << "   ";
            }
        }
    }
    int ymax = helper.yMax(YiBar, n);
    int ymin = helper.yMin(YiBar, n);

    cout << "\nTi    :";
    for (int i = 0; i < n; i++)
    {
        Ti[i] = helper.calculateTi(ymax, ymin, YiBar[i]);
        if (Ti[i] > 9 && i != 0)
        {
            cout << " " << Ti[i] << " ";
        }
        else
        {
            if (Ti[i] < 0)
            {
                cout << "\b" << Ti[i] << "   ";
            }
            else
            {
                cout << Ti[i] << "   ";
            }
        }
    }
    int flag = 0;
    cout << "\nXi    :";
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        if (Di[i] >= 0 && Di[i] < Ti[i])
        {
            flag = 1;
        }
        else if (-Ti[i] <= Di[i] && Di[i] < 0)
        {
            flag = 2;
        }

        if (flag == 1)
        {
            Xi[i] = 2 * Di[i];
        }
        else if (flag == 2)
        {
            Xi[i] = (2 * abs(Di[i])) - 1;
        }
        else if (flag == 0)
        {
            Xi[i] = Ti[i] + abs(Di[i]);
        }

        if (Xi[i] > 9 && i != 0)
        {
            cout << " " << Xi[i] << " ";
        }
        else
        {
            if (Xi[i] < 0)
            {
                cout << "\b" << Xi[i] << "   ";
            }
            else
            {
                cout << Xi[i] << "   ";
            }
        }
    }
    int i, j;
    string unaryCode = "";
    string binaryValue;
    int Block[2][blockSize];
    cout << "\n\n=> Fundamental Squence [ Block 1 ] : ";
    for (i = 0; i < blockSize; i++)
    {
        Block[0][i] = Xi[i];
        unaryCode = helper.getUnaryCode(Block[0][i]);
        cout << unaryCode << " ";
    }
    j = i;
    for (i = 0; i < blockSize; i++, j++)
    {
        Block[1][i] = Xi[j];
    }
    cout << "\n\n=> 1 Slipt  [ Block 2 ] : ";
    for (i = 0; i < blockSize; i++)
    {
        string remaining, last;
        binaryValue = helper.getBinary(Block[1][i], blockSize);
        last = binaryValue.substr(binaryValue.length() - 1);
        remaining = binaryValue.substr(0, binaryValue.length() - 1);
        int decimal = stoi(remaining, 0, 0);
        unaryCode = helper.getUnaryCode(decimal);
        cout << unaryCode << " ";
    }
    getch();
}