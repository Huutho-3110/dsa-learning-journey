/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

long long C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    long long res = 1;
    for (int i = 1; i <= k; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}
class Solution
{
public:
    void solve()
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(k + 1);
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        long long ptlonhon = 0;
        for (int i = 1; i <= k; i++)
        {
            int maxV = n - k + i;
            for (int v = a[i] + 1; v <= maxV; v++)
            {
                ptlonhon += C(n - v, k - i);
            }
        }
        cout << ptlonhon + 1 << "\n";
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