class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>>umap;

        for(auto str:strs)
        {
            auto temp = str;
            sort(temp.begin(),temp.end());
            umap[temp].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto list:umap)
        {
            ans.push_back(list.second);
        }

        return ans;
    }
};