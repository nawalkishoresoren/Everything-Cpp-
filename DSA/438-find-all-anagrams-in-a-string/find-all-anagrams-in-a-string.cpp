class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>freqP(26,0);
        vector<int>freqS(26,0);
        vector<int>ans;

        for(auto c:p)
        {
            freqP[c-'a']++;
        }
        
        int left = 0;
        for(int right = 0;right<s.size();right++)
        {
            freqS[s[right]-'a']++;

            if(right-left+1 > p.size())
            {
                freqS[s[left]-'a']--;
                left++;
            }

            if(right-left+1 == p.size())
            {
                if(freqP==freqS)
                    ans.push_back(left);
            }
        }
        return ans;
        
    }
};