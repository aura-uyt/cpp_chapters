#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // bcz first integer of each row is greater than the last integer of the
    // previous row, all elements of this matrix can be assumed as flattened
    // array of sorted numbers, hence BS

    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[mid / n][mid % n] == target)
        return true;
      else if (matrix[mid / n][mid % n] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return false;
  }
};
