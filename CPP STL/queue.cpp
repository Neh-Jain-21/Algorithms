// 0. std::queue class is a container adapter that gives the programmer the functionality of a queue
// 1. queue is FIFO (first-in, first-out) data structure.
// 2. std::queue provides only specific set of functions.
// 3. std::queue allows to push(insert) at back and pop(remove) from front.
// 4. std::queue gives front, back, push, pop, empty, size.

#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> que)
{
    while (!que.empty())
    {
        cout<<que.front()<<endl;
        que.pop();
    }
}

int main()
{
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    print(que);

    return 0;
}