class Solution {
public:
    bool check(int curr_capacity, vector<int>& weights, int days) {
        int total_days = 1; 
        int temp = 0;

        for (int w : weights) {
            if (w > curr_capacity) return false;

            if (temp + w > curr_capacity) {
                total_days++; 
                temp = w;     
            } else {
                temp += w;
            }
        }
        return total_days <= days; 
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = 1,right = 0;

        //CALCULATING THE RIGHT.
        for(auto weight:weights)
        {
            right += weight;
        }

        int mini_capacity = right; //THIS CAPACITY WILL ALWAYS WORK.

        //DOING BINARY SEARCH ON ANSWER(RANAGE {LEFT,RIGHT})
        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(check(mid,weights,days))
            {
                mini_capacity = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return mini_capacity;
    }
};