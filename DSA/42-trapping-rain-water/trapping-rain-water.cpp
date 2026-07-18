class Solution {
public:
    int trap(vector<int>& height) 
    {
        int res = 0;
        int left = 0, right = height.size()-1; 
        int maxleft = height[left], maxright = height[right];


        while(left<right)
        {
            if(maxleft<=maxright)
            {
                res += (maxleft - height[left]);
                left++;
                maxleft = max(maxleft,height[left]);
            }
            else
            {
                res += (maxright - height[right]);
                right--;
                maxright = max(maxright,height[right]);
            }
        }
        return res; 
    }
};