class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto check:mp){
            if(check.second==1){
                return check.first;
            }
        }
        return -1;
    }
};