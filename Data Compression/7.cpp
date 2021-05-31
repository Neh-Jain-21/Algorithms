// Write a program to generate Rice code with Fundamental Sequence and 1 split option.
#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
using namespace std;

class Helper
{
public:
    int findItration(int nbits)
    {
        double p = pow(2, nbits);
        int power = (int)p;
        int x = power - nbits;
        int k = x / (nbits - 1);
        return k;
    }

    int findMaxIndex(float prob[], int nsym)
    {
        float max = 0;
        int maxIndex = 0;
        for (int i = 0; i < nsym; i++)
        {
            if (prob[i] > max)
            {
                max = prob[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    int findMaxIndex(float prob[], int nsym, int index[], int k)
    {
        float max = 0;
        int maxIndex = 0, flag = 0;
        for (int i = 0; i < nsym; i++)
        {
            flag = 0;
            for (int j = 0; j < k; j++)
            {
                if (i == index[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                if (prob[i] > max)
                {
                    max = prob[i];
                    maxIndex = i;
                }
            }
        }
        return maxIndex;
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

    string getBinary(int n, int bit)
    {
        string binary = decToBinary(n);
        int length = binary.length();
        bit = bit - length;
        for (int i = 0; i < bit; i++)
        {
            binary = "0" + binary;
        }
        return binary;
    }
};

int main()
{
    int nbits, nsym;
    int flag = 0;
    cout << "Enter Number Of Symbol :";
    cin >> nsym;
    cout << "Enter Number of Bits :";
    cin >> nbits;

    string symbol[100];
    float prob[100];

    for (int i = 0; i < nsym; i++)
    {
        cout << "Enter symbol " << (i + 1) << " : ";
        cin >> symbol[i];
    }

    for (int i = 0; i < nsym; i++)
    {
        cout << "Enter Probability " << symbol[i] << " : ";
        cin >> prob[i];
    }

    cout << "\n Current Table  : " << endl
         << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|\t Symbol \t |\t Probability \t|" << endl;
    cout << "|-----------------------------------------------|" << endl;
    for (int i = 0; i < nsym; i++)
    {
        cout << "|\t " << symbol[i] << " \t  \t |\t " << fixed << setprecision(3) << prob[i] << " \t\t|" << endl;
        cout << "|-----------------------------------------------|" << endl;
    }

    Helper helper;
    int k = helper.findItration(nbits);

    int x = 0, index = 0, nsym1 = nsym;
    int maxindex[k];
    while (x != k)
    {
        if (x == 0)
        {
            maxindex[x] = helper.findMaxIndex(prob, nsym);
        }
        else
        {
            maxindex[x] = helper.findMaxIndex(prob, nsym, maxindex, k);
        }
        if (x == k - 1)
        {
            int codeword = 0;
            cout << "|\n\n  Table " << x << " : " << endl;
            cout << "|-----------------------------------------------------------------|" << endl;
            cout << "|\t Symbol \t |\t Probability \t |\t Codeword |" << endl;
            cout << "|-----------------------------------------------------------------|" << endl;
            for (int i = 0; i < nsym; i++)
            {
                flag = 0;
                for (int j = 0; j < x + 1; j++)
                {
                    if (maxindex[j] == i)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "|\t " << symbol[i] << " \t  \t |\t " << fixed << setprecision(3) << prob[i] << " \t \t |\t " << helper.getBinary(codeword, nbits) << "\t  |" << endl;
                    cout << "|-----------------------------------------------------------------|" << endl;
                    codeword = codeword + 1;
                }
            }

            index = 0;
            for (int j = nsym; j <= (nsym - 1) + nsym1; j++)
            {

                symbol[j] = symbol[maxindex[x]] + symbol[index];
                prob[j] = prob[maxindex[x]] * prob[index];
                index = index + 1;
                cout << "|\t " << symbol[j] << " \t  \t |\t " << fixed << setprecision(3) << prob[j] << " \t \t |\t " << helper.getBinary(codeword, nbits) << "\t  |" << endl;
                cout << "|-----------------------------------------------------------------|" << endl;
                codeword = codeword + 1;
            }
            nsym = nsym + index;
            x++;
        }
        else
        {

            cout << "|\n\n  Table " << x << " : " << endl;
            cout << "|-----------------------------------------------|" << endl;
            cout << "|\t Symbol \t |\t Probability \t|" << endl;
            cout << "|-----------------------------------------------|" << endl;

            for (int i = 0; i < nsym; i++)
            {
                flag = 0;
                for (int j = 0; j < x + 1; j++)
                {
                    if (maxindex[j] == i)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "|\t " << symbol[i] << " \t  \t |\t " << fixed << setprecision(3) << prob[i] << " \t\t|" << endl;
                    cout << "|-----------------------------------------------|" << endl;
                }
            }

            index = 0;
            for (int j = nsym; j <= (nsym - 1) + nsym1; j++)
            {

                symbol[j] = symbol[maxindex[x]] + symbol[index];
                prob[j] = prob[maxindex[x]] * prob[index];
                index = index + 1;
                cout << "|\t" << symbol[j] << " \t  \t |\t " << fixed << setprecision(3) << prob[j] << " \t\t|" << endl;
                cout << "|-----------------------------------------------|" << endl;
            }
            nsym = nsym + index;
            x++;
        }
    }
    getch();
}