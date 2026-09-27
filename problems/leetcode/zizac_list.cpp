#include <bits\stdc++.h>
using namespace std;
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) {
      return s;
    }
    vector<string> v(numRows);
    int cnt = 0;
    bool down = false;
    for (char x : s) {
      v[cnt] += x;
      if (cnt == 0 || cnt == numRows - 1) {
        down = !down;
      }
      if (down)
        cnt++;
      else
        cnt--;
    }
    string res = "";
    for (string tmp : v) {
      res += tmp;
    }
    return res;
  }
};