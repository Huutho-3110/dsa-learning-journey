/*
 * Problem: Lexicographical Rank of a Permutation (Combinatorics Approach)
 * Time Complexity: O(N^2)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void solve()
    {
        int n;
        if (!(cin >> n))
            return;
        vector<int> input(n);
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        long long skipped = 0;
        vector<bool> used(n + 2, false);

        for (int i = 0; i < n; i++)
        {
            int current = input[i];
            int smaller_unused_count = 0;
            for (int j = 1; j < current; j++)
            {
                if (!used[j])
                {
                    smaller_unused_count++;
                }
            }
            int remaining_positions = n - 1 - i;
            skipped += smaller_unused_count * fact[remaining_positions];
            used[current] = true;
        }
        cout << skipped + 1 << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution().solve();
    return 0;
}