class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0,right=0;
        int max_fruits = INT_MIN;
        unordered_map<int,int>umap;

        while(right<fruits.size())
        {
            umap[fruits[right]]++;

            while(umap.size()>2)
            {
                umap[fruits[left]]--;

                if(umap[fruits[left]]==0)
                    umap.erase(fruits[left]);

                left++;
            }

            max_fruits = max(max_fruits,right-left+1);
            right++;
        }
        return max_fruits;
    }
};