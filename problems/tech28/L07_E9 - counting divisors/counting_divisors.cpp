/*
 * Problem: Tính số lượng ước số của N modulo 10^9 + 7
 * Time Complexity: O(T) - Chỉ cần duyệt qua T dòng đầu vào.
 * Space Complexity: O(1) - Chỉ sử dụng một vài biến cơ bản để lưu trữ tạm thời.
 */

#include <iostream>

using namespace std;

const int MOD = 1000000007;

class Solution
{
public:
    void solve()
    {
        int T;
        cin >> T;

        long long uoc = 1;

        for (int i = 0; i < T; i++)
        {
            long long p, e;
            cin >> p >> e;
            uoc = (uoc * (e + 1)) % MOD;
        }

        cout << uoc << "\n";
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