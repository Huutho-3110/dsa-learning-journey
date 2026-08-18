/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> kq;
vector<vector<string>> ans;

void Try(int start, string &strN, long long &s, long long curSum)
{
    if (start == (int)strN.size())
    {
        if (curSum == s && kq.size() >= 2)
        {
            ans.push_back(kq);
        }
        return;
    }

    for (int j = start; j < (int)strN.size(); j++)
    {
        string tmp = strN.substr(start, j - start + 1);

        if (tmp.size() >= 2 && tmp[0] == '0')
            return; 

        long long val = stoll(tmp);
        if (curSum + val > s)
            break;

        kq.push_back(tmp);
        Try(j + 1, strN, s, curSum + val);
        kq.pop_back();
    }
}

class Solution
{
public:
    void solve()
    {
        long long n, s;
        cin >> n >> s;
        string strN = to_string(n);
        Try(0, strN, s, 0LL);
        if (ans.empty())
        {
            cout << "28tech" << '\n';
            return;
        }
        for (auto &x : ans)
        {
            for (auto &y : x)
                cout << y << " ";
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
    }
#endif

    Solution solution;
    solution.solve();
    return 0;
}