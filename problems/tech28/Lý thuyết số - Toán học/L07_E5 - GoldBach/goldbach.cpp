/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int num = 1000001;
vector<bool> sieve()
{
    vector<bool> prime(num + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= num; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j <= num; j += i)
            prime[j] = false;
    }
    return prime;
}
class Solution
{
public:
    void solve()
    {
        vector<bool> prime = sieve();
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            for (int i = 2; i <= n / 2; i++)
            {
                if (prime[i] && prime[n - i] && i <= n - i)
                    cout << i << " " << n - i << endl;
            }
        }
        // Implement logic here
    }
};

int main()
{
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    solution.solve();

    return 0;
}