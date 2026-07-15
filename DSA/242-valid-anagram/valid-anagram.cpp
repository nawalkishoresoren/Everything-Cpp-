class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()>t.size())
            return false;
        
        unordered_map<char,int>umap;

        for(auto c:s)
        {
            umap[c]++;
        }
        for(auto ct:t)
        {
            if(umap.find(ct) == umap.end() or umap[ct]==0)
                return false;
            else
                umap[ct]--;
        }
        return true;
    }
};