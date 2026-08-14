/*
 * Problem: Sinh tổ hợp kế tiếp (Next Combination)
 * Time Complexity: O(k) - Trong trường hợp xấu nhất, vòng lặp chạy lùi tối đa k lần.
 * Space Complexity: O(k) - Lưu trữ mảng input có kích thước k.
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void solve()
    {
        int n, k;
        cin >> n >> k;
        int maxBase = n;
        vector<int> input(k);

        for (int i = 0; i < k; i++)
        {
            cin >> input[i];
        }

        int it = k - 1;
        while (it >= 0)
        {
            if (input[it] == maxBase)
            {
                --it;
                --maxBase;
            }
            else if (input[it] < maxBase)
            {
                ++input[it];
                for (int i = it + 1; i < k; i++)
                {
                    input[i] = input[i - 1] + 1;
                }
                break;
            }
        }

        if (it < 0)
        {
            for (int i = 1; i <= k; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
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