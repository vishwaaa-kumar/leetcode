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
        for(auto it : mp)
        {   
            int freq=it.second;
            for(int i=0;i<freq;i++)
                v.push_back(it.first);
        }
        return v;
    }
};