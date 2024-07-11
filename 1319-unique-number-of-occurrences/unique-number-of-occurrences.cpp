class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp, countMap;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for (auto &k: mp) {
            countMap[k.second]++;
            if (countMap[k.second] > 1)
                return false;
        }
        return true;
    }
};