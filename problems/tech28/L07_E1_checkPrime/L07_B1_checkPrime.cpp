/*
*Problem 1. Check if a Number is Prime
Problem Statement
Given a non-negative integer **N**, determine whether it is a prime number.
A prime number is a positive integer that has exactly two positive divisors: **1** and itself. The numbers **0** and **1** are **not** prime.
 Input
A single line containing a non-negative integer N.
Constraints
0 ≤ N ≤ 10^9
Output
Print `YES` if N is a prime number; otherwise, print `NO`.
*/

/*
 * Problem: Check if a Number is Prime
 * Time Complexity: O(√N) cho mỗi test case
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void solve()
    {
        long long n;
        while (cin >> n)
        {
            if (n == 0 || n == 1)
            {
                cout << "NO\n";
                continue;
            }
            bool isPrime = true;
            for (long long i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
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