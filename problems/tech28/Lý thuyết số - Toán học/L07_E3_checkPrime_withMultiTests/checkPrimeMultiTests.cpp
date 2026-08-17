/*
    Problem 3. Prime Number Check with Multiple Test Cases

    Description:
    Check whether each given number is a prime number.

    Input:
    - The first line contains the number of test cases T.
    - Each test case contains an integer n.

    Constraints:
    - 1 <= T <= 1000
    - 0 <= n <= 10^6

    Output:
    - Print "YES" if n is a prime number.
    - Print "NO" otherwise.
    - Each result should be printed on a separate line.
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

class Solution
{
public:
    void solve()
    {
        // Implement logic here
        int T;
        cin >> T;

        while (T--)
        {
            int n;
            cin >> n;

            if (n < 2)
            {
                cout << "NO" << endl;
                continue;
            }

            bool isPrime = true;

            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            cout << (isPrime ? "YES" : "NO") << endl;
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