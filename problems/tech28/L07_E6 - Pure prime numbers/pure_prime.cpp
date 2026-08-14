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

bool nt(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
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
bool csnt(int n)
{
    int sum = 0;
    while (n)
    {
        int temp = n % 10;
        if (temp != 2 && temp != 3 && temp != 5 && temp != 7)
            return false;
        sum += temp;
        n /= 10;
    }
    return (nt(sum));
}
class Solution
{
public:
    void solve()
    {
        int a, b;
        cin >> a >> b;
        int dem = 0;
        for (int i = a; i <= b; i++)
        {
            if (csnt(i) && nt(i))
            {
                ++dem;
            }
        }
        cout << dem << endl;
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