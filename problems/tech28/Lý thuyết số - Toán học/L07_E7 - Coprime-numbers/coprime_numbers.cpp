/*
 * Problem: Find all coprime pairs (i, j) in a given range [a, b] such that i < j.
 * Time Complexity: O((b - a)^2 * \log(b))
 * Space Complexity: O(\log(b)) due to the recursion stack of the GCD function.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    int ucln = gcd(b, a % b);
    return ucln;
}

class Solution
{
public:
    void solve()
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            for (int j = i + 1; j <= b; j++)
            {
                if (gcd(i, j) == 1)
                {
                    cout << "(" << i << "," << j << ")\n";
                }
            }
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