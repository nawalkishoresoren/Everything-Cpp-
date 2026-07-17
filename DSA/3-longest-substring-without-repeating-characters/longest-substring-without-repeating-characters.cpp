class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int char_freq[256] = {0};
        int left = 0,right = 0;
        int max_length = 0;

        while(right<s.size())
        {
            char_freq[s[right]]++;
            
            if(char_freq[s[right]] > 1)
            {
                while(char_freq[s[right]]>1)
                {
                    char_freq[s[left]]--;
                    left++;
                }
            }
            max_length = max(max_length,right-left+1);
            right++;
        }
        return max_length;
    }
};