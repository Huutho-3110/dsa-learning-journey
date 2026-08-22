#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];
bool found = false;

void backtrack(int index, int current_sum, int target)
{

    if (found)
        return;

    if (current_sum == target)
    {
        found = true;
        return;
    }

    if (index > n || current_sum > target)
    {
        return;
    }
    backtrack(index + 1, current_sum + a[index], target);
    backtrack(index + 1, current_sum, target);
}

class Solution
{
public:
    void solve()
    {
        cin >> n;
        int total_sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            total_sum += a[i];
        }
        if (total_sum % 2 != 0)
        {
            cout << 0 << "\n";
            return;
        }

        int target = total_sum / 2;
        found = false;
        sort(a + 1, a + n + 1, greater<int>());
        backtrack(1, 0, target);
        if (found)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    solution.solve();

    return 0;
}