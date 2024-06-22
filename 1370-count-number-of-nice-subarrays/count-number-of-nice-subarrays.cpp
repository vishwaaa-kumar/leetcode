class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd = 0, l = 0, c = 0;
        for (int r = 0; r < nums.size(); r++) {
            odd += (nums[r] & 1);
            // Ensure the current window [l, r] has at least k odd numbers
            while (l <= r && odd > k) {
                odd -= (nums[l] & 1);
                l++;
            }
            // If the current window [l, r] has exactly k odd numbers
            if (odd == k) {
                int l1 = l;
                // Count nice subarrays ending at r
                while (l1 <= r && (nums[l1] & 1) == 0) {
                    l1++;
                }
                c += l1 - l + 1;
            }
        }
        return c;
    }
};