/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

bool sinh(vector<int> &v, int n, int k)
{
    int i = k;
    while (i > 0 && v[i] == n - k + i) //O(k)
    {
        --i;
    }
    if (i == 0)
        return false;
    else
    {
        ++v[i];
        for (int j = i + 1; j <= k; j++) //O(k)

        {

            v[j] = v[j - 1] + 1;
        }
    }
    return true;
}
class Solution
{
public:
    void solve()
    {
        int n, k;
        cin >> n >> k;
        vector<int> base(k + 1);
        for (int i = 1; i <= k; i++) //O(k)
        {
            base[i] = i;
        }
        do
        {
            for (int j = 1; j <= k; j++)//O(k^2 )
                cout << base[j];
            cout << '\n';
        } while (sinh(base, n, k));
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