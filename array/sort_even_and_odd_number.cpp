#include <bits/stdc++.h>
using namespace std;

vector<int> EvenOdd(vector<int> &A)
{
    int nextEven = 0, nextOdd = A.size();

    while(nextEven < nextOdd)
    {
        if(A[nextEven] % 2 == 0)
        {
            nextEven++;
        }
        else
        {
            swap(A[nextEven], A[--nextOdd]);
        }
    }
    return A;
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    arr.resize(n); 

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = EvenOdd(arr);

    for(auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}
