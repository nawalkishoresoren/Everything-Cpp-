class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int window_sum = 0;
        int left =0, right = 0;

        for(right=0;right<k;right++)
        {
            window_sum += nums[right];
        }

        int max_sum = window_sum;

        while(right<nums.size())
        {
            window_sum += nums[right++];
            window_sum -= nums[left++];
            max_sum = max(max_sum,window_sum);
        }
        return (double)max_sum/k;

    }
};