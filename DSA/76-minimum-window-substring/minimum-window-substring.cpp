class Solution {
public:
    string minWindow(string s, string t) 
    {
        int char_freq[256] = {0};
        int left = 0, right = 0;
        int start_idx = -1;
        int minLenghth = INT_MAX;
        int count = 0;

        for(auto c:t)
        {
            char_freq[c]++;
        }

        while(right<s.size())
        {
            if(char_freq[s[right]] > 0 )
            {
                count++;
            }
            char_freq[s[right]]--;
            while(count == t.size())
            {
                if(right-left+1 < minLenghth)
                {
                    minLenghth = right-left+1;
                    start_idx = left;
                }
                char_freq[s[left]]++;
                if(char_freq[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
            right++;
        }
        return start_idx==-1?"":s.substr(start_idx,minLenghth);
    }
};