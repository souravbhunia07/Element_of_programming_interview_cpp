#include <bits/stdc++.h>
using namespace std;

vector<int> PlusOne(vector<int> A)
{
    int carry = 0;
    A.back()++;
    for(int i = A.size() - 1; i >= 0; i--)
    {
        A[i] += carry;
        carry = A[i] / 10;
        A[i] %= 10;
    }

    if(carry > 0)
    {
        A.insert(A.begin(), carry);
    }

    return A;
}

int main()
{
    int n;
    vector<int> num;
    cin >> n;

    while(n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    reverse(num.begin(), num.end());

    vector<int> ans = PlusOne(num);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
