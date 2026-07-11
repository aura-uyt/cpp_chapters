#include <bits/stdc++.h>
using namespace std;

class Solution {
  int countStudents(vector<int> &arr, int pages) {
    int students = 1;
    long long countPages = 0;
    for (int i = 0; i < arr.size(); i++) {
      countPages += arr[i];
      if (countPages > pages) {
        students++;
        countPages = arr[i];
      }
    }
    return students;
  }
  int findPages(vector<int> &arr, int n, int m) {
    if (m > n)
      return -1;
    int low = INT_MIN, high = 0;
    for (int i : arr) {
      low = max(low, i);
      high += i;
    }
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int students = countStudents(arr, mid);
      if (students > m)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
  }
};
