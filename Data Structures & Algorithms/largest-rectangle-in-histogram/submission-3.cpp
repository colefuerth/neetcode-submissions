#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#define MAX(a, b) (a > b ? a : b)

class Solution {
public:
    int largestRectanglePartition(vector<int>::iterator l, vector<int>::iterator r) {
        if (l >= r) return 0;
        cout << "partition [" << *l;
        for (auto it = l+1; it < r; cout << "," << *(it++));;
        cout << "], min=";
        vector<int>::iterator m = min_element(l, r);
        cout << *m << ", area=";
        int a = distance(l, r) * (*m);
        cout << a << endl;
        int x = largestRectanglePartition(l, m);
        int y = largestRectanglePartition(m + 1, r);
        x = MAX(x, y);
        return MAX(a, x);
    }
    int largestRectangleArea(vector<int>& heights) {
        return largestRectanglePartition(heights.begin(), heights.end());
    }
};
