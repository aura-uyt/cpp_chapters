#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();
    int maxCount = 0;
    int rowIndex = -1;
    for (int i = 0; i < n; i++) {
      int low = 0, high = m - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[i][mid] == 1)
          high = mid - 1;
        else
          low = mid + 1;
      }
      int numOf1s = m - low;
      if (numOf1s > maxCount) {
        maxCount = numOf1s;
        rowIndex = i;
      }
    }
    return rowIndex;
  }
};
