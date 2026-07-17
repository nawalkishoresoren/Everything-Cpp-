class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(i>0 and nums[i] == nums[i-1])
                continue;
            
            int new_target = -nums[i];
            int left = i+1,right = nums.size()-1;

            while(left<right)
            {
                int sum = nums[left] + nums[right];

                if(sum==new_target)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});

                    while(left<right and nums[left]==nums[left+1])
                        left++;
                    
                     while(left<right and nums[right]==nums[right-1])
                        right--;
                    
                    left++;
                    right--;

                }
                else if(sum<new_target)
                {
                    left++;
                }
                else
                {
                    right--;
                }

            }
        }
        return ans;
        
    }
};