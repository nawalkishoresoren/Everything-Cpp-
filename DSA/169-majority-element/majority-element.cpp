class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int majority_element = nums[0];
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == majority_element)
            {
                count++;
            }
            else
            {
                if(count>0)
                {
                    count--;
                }
                else{
                    majority_element = nums[i];
                    count++;
                }
            }
        }
        return majority_element;
    }
};