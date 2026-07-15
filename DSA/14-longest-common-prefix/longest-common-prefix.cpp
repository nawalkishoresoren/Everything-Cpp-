class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());

        int i=0;
        while(i<strs.front().size() and i< strs.back().size() and strs.front()[i] == strs.back()[i])
        {
            i++;
        }
        return strs.front().substr(0,i);
    }
};