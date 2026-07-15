class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int>st(nums.begin(),nums.end());
        return !(nums.size()==st.size());
    }
};