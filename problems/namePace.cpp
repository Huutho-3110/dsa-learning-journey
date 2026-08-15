/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;

bool named(vector<string> &name, int n)
{
    int i = n - 1;
    while (i > 0 && name[i] > name[i + 1])
        --i;
    if (i == 0)
        return false;
    int j = n;
    while (name[i] > name[j])
        --j;
    swap(name[i], name[j]);
    reverse(name.begin() + i + 1, name.begin() + n + 1);
    return true;
}

class Solution
{
public:
    void solve()
    {
        int n;
        cin >> n;
        set<string> se;
        vector<string> name;
        name.push_back("0");
        for (int i = 1; i <= n; i++)
        {
            string temp;
            cin >> temp;
            se.insert(temp);
        }
        for (auto x : se)
        {
            name.push_back(x);
        }
        do
        {
            for (int t = 1; t <= n; t++)
                cout << name[t] << " ";
            cout << '\n';
        } while (named(name, n));
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