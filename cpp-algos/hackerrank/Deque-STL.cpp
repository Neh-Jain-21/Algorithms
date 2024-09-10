#include <iostream>
#include <algorithm>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k)
{
	int start=0,end=n-k+1;
	deque<int> dqu;
	for (int i = 0; i < n; i++)
	{
		dqu.push_back(arr[i]);
	}
	while (start!=end)
	{
		cout << *max_element(dqu.begin(),dqu.begin()+k) <<" ";
		dqu.pop_front();
		start++;
	}
	cout<<endl;	
}

int main()
{
	int t;
	cin>>t;
	while(t>0) 
    {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
        {
      		cin >> arr[i];
        }
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}