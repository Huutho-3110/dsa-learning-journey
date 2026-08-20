/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, S, sumAll = 0;
ll visited[10000];
ll money[10000];

int minC = 1e9;
void Try(ll start, ll curMoney, int cnt)
{
    if (cnt >= minC)
        return;
    if (curMoney == S)
    {
        minC = cnt;
        return;
    }
    for (int j = start; j <= n; j++)
    {
        if (j > start && money[j] == money[j - 1])
            continue;
        if (!visited[j] && curMoney + money[j] <= S)
        {

            visited[j] = 1;
            Try(j + 1, curMoney + money[j], cnt + 1);
            visited[j] = 0;
        }
    }
}
class Solution
{
public:
    void solve()
    {
        cin >> n >> S;
        for (ll i = 1; i <= n; i++)
        {
            cin >> money[i];
            sumAll += money[i];
        }
        if (sumAll < S)
        {
            cout << -1 << "\n";
            return;
        }
        sort(money + 1, money + n + 1, greater<ll>());
        Try(1, 0, 0);
        if (minC == 1e9 || minC == 0)
            cout << -1 << "\n";
        else
            cout << minC << "\n";
    }
};

int main()
{
    // Tối ưu hóa chuẩn I/O cho hiệu năng cao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Mẹo đọc file cục bộ, không ảnh hưởng đến GitHub Actions workflow
#ifndef ONLINE_JUDGE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        // Bỏ comment dòng dưới nếu bạn muốn kết quả in thẳng ra file output.txt
        // freopen("output.txt", "w", stdout);
    }
#endif

    Solution solution;
    solution.solve();

    return 0;
}