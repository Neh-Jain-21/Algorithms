// 0. copy Copies the elements in the range, defined by [first, last), to another range beginning at d_first.
// 1. copy_if only copies if predicate returns true.
// 2. if source and destination range are overlapping then the behavior is undefined.


//We can partially copy elements using copy() function.
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;

void print(vector<int>& vec)
{
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
}

int main()
{
    vector<int> from_vector(10);
    iota(from_vector.begin(),from_vector.end(),0);

    //size of vector must be passed
    vector<int> to_vector1(from_vector.size());
    copy(from_vector.begin(),from_vector.end(),to_vector1.begin());
    print(to_vector1);

    //size of vector not passed
    vector<int> to_vector2;
    copy(from_vector.begin(),from_vector.end(),back_inserter(to_vector2));
    print(to_vector2);

    //equivalent to
    vector<int> to_vector = from_vector;

    cout<<"Odd No. into vectors are: ";
    vector<int> to_vector3(5);
    copy_if(from_vector.begin(),from_vector.end(),to_vector3.begin(),[](int x){ return (x%2)==1; });
    print(to_vector3);

    return 0;
}