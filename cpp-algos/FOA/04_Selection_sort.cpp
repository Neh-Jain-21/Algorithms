#include<iostream>
#include<algorithm>
#include<bits/stdc++.h> 
#include<sys/time.h>
#include<time.h>
#include<vector>
#include<conio.h>
using namespace std;

class Sort
{
    int size=10000;
    vector<int> array;

public:
    
    Sort()
    {
        array.reserve(size);
        for (int i = 0; i < size; i++)
        {
            array.push_back(0);
        }
    }

    int showSize()
    {
        return size;
    }
    void changeSize()
    {
        cout<<"Enter new Size=";
        cin>>size;
        array.reserve(size);
        array.clear();
        for (int i = 0; i < size; i++)
        {
            array.push_back(0);
        }
    }
    void getAutomaticRandomData()
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            array[i]=rand()%10;
        }
    }
    void getAutomaticSequentialData()
    {
        array.clear();
        for (int i = 0; i < size; i++)
        {
            array.push_back(i);
        }
    }
    void getUserData()
    {
        cout<<"Enter Size=";
        cin>>size;
        array.clear();
        array.reserve(size);
        for (int i = 0; i < size; i++)
        {
            int data;
            cout<<"Enter Data ["<<i+1<<"]=";
            cin>>data;
            array.push_back(data);
        }
    }
    void sortData()
    {
        int Min;
        for(int i=0;i<=size;i++)
        {
            Min=i;
            for(int j=i+1;j<=size;j++)
            {
                if(array[j]<array[Min])
                {
                    Min=j;
                }
            }
            if(Min!=i)
            {
                int temp;
                temp=array[Min];
                array[Min]=array[i];
                array[i]=temp;
            }
        }
    }
    bool issorted()
    {
        bool flag=true;
        for(int i=0;i<size && flag;i++)
        {
            if(array[i]>array[i+1])
            {
                flag=false;
            }
        }
        return flag;
    }
    void showData()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    //struct timeval st,en;
    clock_t st,en;
    int choice;
    double Time=0;
    Sort s;    
    while(choice!=6)
    {
        system("cls");
        s.showData();
        cout << "-----------------------\n";
        cout << "Size = "<<s.showSize()<<endl;
        cout << "-----------------------\n";
        cout << "1. Change Size"<<endl;
        cout << "2. Insert Random Data"<<endl;
        cout << "3. Insert Sequential Data"<<endl;
        cout << "4. Insert Own Data"<<endl;
        cout << "5. Sort"<<endl;
        cout << "6. Exit"<<endl;
        cout << "-----------------------\n";
        cout <<"Choice:";
        cin >>choice;
        switch(choice)
        {
            case 1:
                s.changeSize();
                break;
            case 2:
                s.getAutomaticRandomData();
                break;
            case 3:
                s.getAutomaticSequentialData();
                break;
            case 4:
                s.getUserData();
                break;
            case 5:
                if(s.issorted())
                {
                    cout<<"Already Sorted";
                    getch();
                    break;
                }
                else
                {
                    try
                    {
                        //gettimeofday(&st,0);
                        st=clock();
                        s.sortData();
                        en=clock();
                        //gettimeofday(&en,0);
                        //Time=(((float)(en.tv_sec-st.tv_sec)*1000000)+((float)(en.tv_usec-st.tv_usec)));
                        Time=double(en-st)/double(CLOCKS_PER_SEC);
                        cout<<fixed<<"Execution Time="<<Time*1000<<" ms"<<setprecision(4)<<endl;
                        getch();
                        break;
                    }
                    catch(exception e)
                    {
                        cout<<e.what()<<endl;
                        break;
                    }
                }
            case 6:
                break;
            default:
                cout << "Invalid choice"<<endl;
                getch();
                break;
        }
    }
    return 0;
}