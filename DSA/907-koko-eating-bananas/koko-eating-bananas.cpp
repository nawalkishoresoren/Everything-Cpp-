class Solution {
public:
    long long time(int speed,vector<int>& piles)
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
        sort(piles.begin(),piles.end());
        int n = piles.size()-1;
        int left = 1, right = piles[n];
        int min_speed = piles[n];

        while(left<=right)
        {
            int mid = left + (right - left)/2;
            if(time(mid,piles)<=h)
            {
                min_speed = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return min_speed;
    }
};