/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void solve()
    {

        int n;
        cin >> n;
        vector<int> input(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> input[i];
        }
        int i = n - 1;
        while (i >= 1 && input[i] > input[i + 1])
        {
            --i;
        }
        if (i < 1)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            int j = n;
            while (input[i] > input[j])
                --j;
            swap(input[i], input[j]);
            reverse(input.begin() + i + 1, input.begin() + n + 1);
            for (int i = 1; i <= n; i++)
            {
                cout << input[i] << " ";
            }
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