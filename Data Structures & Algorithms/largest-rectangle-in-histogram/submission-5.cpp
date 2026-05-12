#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    int largestRectanglePartition(vector<int>::iterator l, vector<int>::iterator r) {
        if (l == r) return 0;
        int a, x, y;
        vector<int>::iterator m = min_element(l, r);
        a = distance(l, r) * (*m);
        x = largestRectanglePartition(l, m);
        y = largestRectanglePartition(m + 1, r);
        return MAX(a, MAX(x, y));
    }
    int largestRectangleArea(vector<int>& heights) {
        return largestRectanglePartition(heights.begin(), heights.end());
    }
};
