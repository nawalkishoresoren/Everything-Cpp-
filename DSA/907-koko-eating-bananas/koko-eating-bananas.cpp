class Solution {
public:
    long long time(int speed, vector<int>& piles)
    {
        long long total_time = 0;
        for(auto pile:piles)
        {
            if(pile%speed == 0)
                total_time += pile/speed;
            else
                total_time += (pile/speed)+1;
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1,right = 0;
        for(auto pile:piles)
        {
            right = max(right,pile);
        }

        int min_time = right;
        while(left<=right)
        {
            int mid = left + ( right - left)/2;

            if(time(mid,piles)<=h)
            {
                min_time = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return min_time;
    }
};