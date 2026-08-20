/*
 * Problem:
 * Time Complexity: O()
 * Space Complexity: O()
 */

#include <bits/stdc++.h>

using namespace std;
int a[100], n, cnt;
bool final = false;

// Khởi tạo
// a[1] = n; cnt = 1;

void sinh()
{
    int i = cnt;
    while (i >= 1 && a[i] == 1)
    {
        i--;
    }
    if (i == 0)
    {
        final = true;
    }
    else
    {
        a[i]--;
        int conThieu = cnt - i + 1;

        cnt = i;

        int q = conThieu / a[i];
        int r = conThieu % a[i];
        if (q > 0)
        {
            for (int j = 1; j <= q; j++)
            {
                cnt++;
                a[cnt] = a[i];
            }
        }
        if (r > 0)
        {
            cnt++;
            a[cnt] = r;
        }
    }
}

class Solution
{
public:
    void solve()
    {
        cin >> n;
        a[1] = n;
        cnt = 1;
        int sum = 0;
        vector<string> ans;
        while (!final)
        {

            string tmp = "";
            for (int i = 1; i <= cnt; i++)
            {
                if (a[i] == 0)
                    break;
                else
                {

                    tmp += to_string(a[i]);
                    if (a[i + 1] != 0)
                        tmp += "+";
                }
            }
            if (tmp[(int)tmp.size() - 1] == '+')
                tmp.pop_back();
            ans.push_back(tmp);
            sum++;
            sinh();
        }
        cout << sum << endl;
        for (int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
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