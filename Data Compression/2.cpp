// Write a code to verify that input code is a prefix code or not.
#include <iostream>
#include <conio.h>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

string str1 = "ccabccbccc";
string a = "00";
string b = "01";
string c = "1";

class Prefix
{
    struct New_Node
    {
        char data;
        size_t freq;
        New_Node *left;
        New_Node *right;
        New_Node(char data, size_t freq) : data(data), freq(freq), left(NULL), right(NULL)
        {
        }
        ~New_Node()
        {
            delete left;
            delete right;
        }
    };

    struct compare
    {
        bool operator()(New_Node *l, New_Node *r)
        {
            return (l->freq > r->freq);
        }
    };

    New_Node *top;

    void print_Code(New_Node *root, string str)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->data == '$')
        {
            print_Code(root->left, str + "0");
            print_Code(root->right, str + "1");
        }

        if (root->data != '$')
        {
            // cout << root->data <<" : " << str << "\n";
            print_Code(root->left, str + "0");
            print_Code(root->right, str + "1");
        }
    }

public:
    Prefix(){};
    ~Prefix()
    {
        delete top;
    }
    void Generate_Huffman_tree(vector<char> &data, vector<size_t> &freq, size_t size)
    {
        New_Node *left;
        New_Node *right;
        priority_queue<New_Node *, vector<New_Node *>, compare> minHeap;

        for (size_t i = 0; i < size; ++i)
        {
            minHeap.push(new New_Node(data[i], freq[i]));
        }

        while (minHeap.size() != 1)
        {
            left = minHeap.top();
            minHeap.pop();

            right = minHeap.top();
            minHeap.pop();

            top = new New_Node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minHeap.push(top);
        }
        print_Code(minHeap.top(), "");
        cout << "It is Prefix Code";
    }
};

string printDistinctCharacters(string str)
{
    int count = str.length();
    string rstr;
    char un[count];
    int len = 0;
    set<char> set1;
    for (int i = 0; i < count; i++)
    {
        set1.insert(str[i]);
    }
    for (const auto &e : set1)
    {
        rstr = rstr + e;
    }
    return rstr;
}

int main()
{
    Prefix set1;
    vector<char> data;
    vector<size_t> freq;

    string str3;
    int len = str1.length();
    int f[len], fa[len];
    char ch[len];

    cout << "String :- " << str1 << endl
         << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl
         << endl;

    str3 = printDistinctCharacters(str1);

    for (int i = 0; i < str3.length(); i++)
    {
        data.insert(data.end(), str3[i]);
    }

    //Frequency of characters
    for (int i = 0; i < len; i++)
    {
        f[i] = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (str1[i] == str1[j])
            {
                f[i]++;
                str1[j] = '0';
            }
        }
    }
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str1[i] != '0')
        {
            ch[count] = str1[i];
            fa[count] = f[i];
            count++;
        }
    }

    for (int i = 0; i < count; i++)
    {
        freq.insert(freq.end(), fa[i]);
    }

    size_t size = data.size();
    set1.Generate_Huffman_tree(data, freq, size);
    getch();
    return 0;
}