class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size()-1;

        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return mid;
            
            if(nums[left]<=nums[mid])
            {
                //LEFT HALF IS SORTED
                if(nums[left]<=target and target<nums[mid])
                {
                    //TARGET PRESENT IN THIS PART
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
            else
            {
                //RIGHT HALF IS SORTED.
                if(nums[mid]<target and target<=nums[right])
                {
                    //TARGET PRESENT IN THIS PART
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};