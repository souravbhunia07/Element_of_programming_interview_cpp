#include <bits/stdc++.h>
using namespace std;

string Multiply(string &A, string &B)
{
    int n = A.length();
    int m = B.length();
    vector<int> ans(n + m, 0);

    if(n == 0 || m == 0)
    {
        return "0";
    }

    string res = "";

    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            ans[i + j + 1] += (A[i] - '0') * (B[j] - '0');
            ans[i + j] += ans[i + j + 1] / 10;
            ans[i + j + 1] = ans[i + j + 1] % 10;
        }
    }

    int i = 0;
    while(i < ans.size() && ans[i] == 0)
    {
        i++;
    }

    while(i < ans.size())
    {
        res += to_string(ans[i]);
        i++;
    }

    return res.empty() ? "0" : res;
}


int main()
{
    string a, b;
    cin >> a >> b;

    cout << Multiply(a, b) << endl;
    return 0;
}
