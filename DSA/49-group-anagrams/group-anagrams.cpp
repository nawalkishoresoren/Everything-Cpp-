class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>umap;
        for(auto str:strs)
        {
            auto temp = str;
            sort(temp.begin(),temp.end());
            umap[temp].push_back(str);
        }
        for(auto list:umap)
        {
            ans.push_back(list.second);
        }
        return ans;

    }
};