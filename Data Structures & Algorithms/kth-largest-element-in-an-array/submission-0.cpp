class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> k_largest(nums.begin(), nums.end());
        for (auto i = 0; i < k - 1; ++i) {
            k_largest.pop();
        }
        return k_largest.top();
    }
};
