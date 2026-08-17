/*
 Problem 49. Count Distinct Strings

 Problem Statement

Have you ever heard of the Multinomial Coefficient? This concept can help you solve the following problem.

Given a string, your task is to determine the number of distinct strings that can be formed by rearranging its characters.

> Note: If you are not familiar with strings yet, consider learning the basics of string manipulation first, then come back and solve this problem.

Input

A single string consisting only of lowercase English letters (a–z).

Constraints


1 ≤ n ≤ 10^6


where n is the length of the string.

 output

Print the number of distinct strings that can be formed by rearranging the characters of the given string, modulo 10^9 + 7.


*/
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
const long long MOD = 1e9 + 7;
long long binpow(long long a, long long b, long long mod)
{
    long long res = 1;
    if (b == 0)
        return 1;
    long long half = binpow(a, b / 2, mod);
    res = (half * half) % mod;
    if (b % 2)
    {
        res = (res * a) % mod;
    }
    return res;
}
class Solution
{
public:
    void solve()
    {
        // Implement logic here
        string s;
        cin >> s;
        int n = s.size();
        vector<long long> frac(n + 1, 1);
        frac[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            frac[i] = frac[i - 1] * i % MOD;
        }
        long long ans = frac[n];
        vector<int> fre(256, 0);
        for (char x : s)
        {
            fre[(unsigned char)x]++;
        }
        for (int i = 0; i < 256; i++)
        {
            if (fre[i] == 0)
                continue;
            long long temp = binpow(frac[fre[i]], MOD - 2, MOD);
            ans = ans * temp % MOD;
        }
        cout << ans << endl;
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