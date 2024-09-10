// 0. std::unordered_multiset is an associative container that contains set of possibly non-unique objects.
// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets. 
// 4. This allows fast access to individual elements, because after computing the hash of the value it refers to 
//    the exact bucket the element is placed into.

// WHY UNORDERED_MULTISET
// 0. maintain a collection of non-uniqe items with fast insertion and removal.

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_multiset<int> uset={4,1,2,3,9,4,3,2,9,8,10};

    auto search=uset.find(2);
    if (search!=uset.end())
    {
        cout<<"Found "<<(*search)<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    for (auto elm: uset)
    {
        cout<<elm<<" ";
    }
    cout<<endl;
    cout<<uset.count(4)<<endl;
    return 0;
}