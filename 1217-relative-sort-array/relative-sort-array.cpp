class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        map<int, int> mp;
        for (int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            while(mp.find(arr2[i]) != mp.end() && mp[arr2[i]]-- != 0)
                v.push_back(arr2[i]);
        }
        sort(arr1.begin(), arr1.end());
        for (int i = 0; i < arr1.size(); i++) {
            while(mp.find(arr1[i]) != mp.end() && mp[arr1[i]]-- > 0)
                v.push_back(arr1[i]);
        }
        return v;
    }
};