class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int left = 0, right = 0;
        int char_freq[256] = {0};
        int res = 0, maxf = 0;
        while(right<s.size())
        {
            char_freq[s[right] - 'A']++;
            maxf = max(maxf,char_freq[s[right] - 'A']);
            while ((right - left + 1) - maxf > k)
            {
                char_freq[s[left] - 'A']--;
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};