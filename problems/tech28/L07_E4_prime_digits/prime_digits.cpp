/*

    [Number Theory - Mathematics].Problem 4. Prime Numbers and Prime Digits

    Write a program to count how many numbers between a and b satisfy both of the following conditions :

    The number itself is a prime number.Every digit of the number is also a prime digit.

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
#include <math.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isDigit(int n)
{
    while (n)
    {
        int temp = n % 10;
        if (temp != 2 && temp != 3 && temp != 5 && temp != 7)
            return false;
        temp /= 10;
    }
    return true;
}

void solve1()
{
    long long a, b;
    cin >> a >> b;
    int cnt = 0;
    vector<bool> isPrime(b + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= b; i++)
    {
        if (!isPrime[i])
            continue;
        for (long long j = i * i; j <= b; j += i)
        {
            isPrime[j] = false;
        }
    }
    for (long long i = a; i <= b; i++)
    {
        if (!isPrime[i])
            continue;
        long long temp = i;
        bool pass = true;
        while (temp)
        {
            if (!isPrime[temp % 10])
            {
                pass = false;
                break;
            }
            temp /= 10;
        }
        if (pass)
            ++cnt;
    }
    // Implement logic here
    cout << cnt << endl;
}
void solve2()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i) && isDigit(i))
            cnt++;
    }
    cout << cnt << endl;
}
class Solution
{
public:
    void solve()
    {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for (int i = a; i <= b; i++)
        {
            if (isPrime(i) && isDigit(i))
                cnt++;
        }
        cout << cnt << endl;
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