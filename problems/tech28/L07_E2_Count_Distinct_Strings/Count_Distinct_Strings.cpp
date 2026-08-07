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
#include <map>

using namespace std;

long long binpow(long long a, long long b, long long mod)
{
    if (b == 0)
        return 1;

    long long half = binpow(a, b / 2, mod);
    long long result = (half * half) % mod;

    if (b % 2)
        result = (result * a) % mod;

    return result;
}
vector<int> fre(string s)
{
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    vector<int> k;
    for (auto x : mp)
    {
        k.push_back(x.second);
    }
    return k;
}
long long legendre(long long n, long long p)
{
    long long ans = 0;

    while (n)
    {
        n /= p;
        ans += n;
    }

    return ans;
}
vector<bool> sieve(int n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (!prime[i])
            continue;

        for (int j = i * i; j <= n; j += i)
            prime[j] = false;
    }

    return prime;
}

class Solution
{
public:
    void solve()
    {
        // Implement logic here
        string s;
        cin >> s;
        const int n = s.size();
        vector<bool> sieveN = sieve(n);
        map<int, int> legN;
        for (int i = 0; i <= (int)sieveN.size(); i++)
        {
            if (!sieveN[i])
                continue;
            legN[i] = legendre(n, i);
        }
        vector<int> k = fre(s);
        for (int i = 0; i < (int)k.size(); i++)
        {
            vector<bool> tempSieve = sieve(k[i]);
            for (int j = 0; j < (int)tempSieve.size(); j++)
            {
                if (!tempSieve[j])
                    continue;
                legN[j] -= legendre(k[i], j);
            }
        }
        int res = 0;
        const int MOD = 1e9 + 7;
        for (auto x : legN)
        {
            res += binpow(x.first, x.second, MOD);
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