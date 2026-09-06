/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    void solve()
    {
        ll n, cphi = 0;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++)
        {
            ll tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        while (pq.size() > 1)
        {
            ll F = pq.top();
            pq.pop();
            ll S = pq.top();
            pq.pop();
            ll sum = F + S;
            cphi += sum;
            pq.push(sum);
        }
        cout << cphi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
    }
#endif

    Solution solution;
    solution.solve();

    return 0;
}