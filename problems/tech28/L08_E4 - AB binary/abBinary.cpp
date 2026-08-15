/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

void sinh(vector<char> &v)
{
    int n = (int)v.size();
    int i = n - 1;
    while (i > 0 && v[i] == '1')
    {
        v[i] = '0';
        --i;
    }
    if (i >= 0)
    {
        v[i] = '1';
    }
}

class Solution
{
public:
    void solve()
    {
        // Implement logic here
        int n;
        cin >> n;
        vector<char> base(n + 1, '0');
        int max = 1 << n;
        int cnt = 0;
        while (true)
        {
            for (int i = 1; i <= n; i++)
            {
                if (base[i] == '0')
                    cout << "B";
                else if (base[i] == '1')
                    cout << "A";
            }
            cout << '\n';
            ++cnt;
            sinh(base);
            if (cnt == max)
                break;
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