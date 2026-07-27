#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // matrix sorted row & col wise, hence matrix[0][0] will be smallest
    // element & matrix[n-1][m-1] be largest but elements on top right and
    // bottom left are special we can do BS on them, bcz let's take top left
    // every element to it's left is smaller & every element to it's bottom
    // bigger means in a sorted fashion somewhat, can do BS on from this
    // traverse to bottom or left checking where x lies

    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0) {
      if (target == matrix[i][j])
        return true;
      else if (target < matrix[i][j])
        j--; // search left (smaller)
      else
        i++; // search below (bigger)
    }
    return false;
  }
};
