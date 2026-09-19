#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeString2(string s, int &i)
    {
        string res = "";
        while (i < s.size() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string readDecode = decodeString2(s, i);
                i++;
                while (k-- > 0)
                {
                    res += readDecode;
                }
            }
            else
            {
                res += s[i];
                i++;
            }
        }
        return res;
    }
    string decodeString(string s)
    {
        int i = 0;
        return decodeString2(s, i);
    }

    string decodeString3(string s)
    {
        stack<string> str;
        stack<int> loop;
        int k = 0;
        string res = "";
        for (char x : s)
        {

            if (isdigit(x))
            {
                k = k * 10 + (x - '0');
            }
            else if (x == '[')
            {
                str.push(res);
                loop.push(k);
                k = 0;
                res = "";
            }
            else if (x == ']')
            {
                string tmp = "";
                string prv = str.top();
                str.pop();
                int repeat = loop.top();
                loop.pop();
                while (repeat--)
                {
                    tmp += res;
                }
                res = prv + tmp;
            }
            else
            {
                res += x;
            }
        }
        return res;
    }
};