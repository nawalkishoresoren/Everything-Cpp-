class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size()-1;
        int curr_water = 0, max_water = INT_MIN;

        while(left<right)
        {
            if(height[left]<=height[right])
            {
                curr_water = height[left] * (right-left);
                left++;
            }
            else
            {
                curr_water = height[right] * (right-left);
                right--;
            }
            max_water = max(max_water,curr_water);
        }
        return max_water;
    }
};