/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

vector<bool> sieve(long long n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;
        for (long long j = i * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }
    return isPrime;
}

class Solution
{
public:
    void solve()
    {
        long long n;
        cin >> n;
        long long temp = sqrt(n);
        vector<bool> prime = sieve(temp);
        for (long long i = 0; i <= temp; i++)
        {
            if (prime[i])
                cout << i * i << " ";
        }
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