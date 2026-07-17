# MoEngage Backend Interview Preparation Notes
> Clean, readable notes with runnable C++ code.

---

# HashMap 
🔗 LeetCode: https://leetcode.com/problems/two-sum/
## Two Sum
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int>umap;

        for(int i=0;i<nums.size();i++)
        {
            int new_target = target - nums[i];
            if(umap.find(new_target) == umap.end())
            {
                umap[nums[i]] = i;
            }
            else
            {
                return {umap[new_target],i};
            }
        }
        return {-1,-1};
    }
};
```
## Group Anagrams
```cpp
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
```
## Longest Consecutive Sequence
🔗 LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>umap;
        for(auto num:nums)
        {
            umap[num]++;
        }
        int max_count = 0;
        for(auto num:umap)
        {
            if(umap.find(num.first-1) == umap.end())
            {
                int count = 1;
                auto temp = num.first;
                while(umap.find(temp+1) != umap.end())
                {
                    temp = temp+1;
                    count++;
                }
                max_count = max(max_count,count);
            }
            
        }
        return max_count;
    }
};
```
## 347. Top K Frequent Elements
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int,int>umap;
        for(auto num:nums)
        {
            umap[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto freq_pair:umap)
        {
            pq.push({freq_pair.second,freq_pair.first});
            if(pq.size()>k)
                pq.pop();
        }

        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
```
## Subarray Sum Equals K
🔗 LeetCode: https://leetcode.com/problems/subarray-sum-equals-k/
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>umap;
        umap[0] = 1;

        int prefix_sum = 0;
        int count = 0;

        for(auto num:nums)
        {
            prefix_sum+=num;

            if(umap.find(prefix_sum-k) != umap.end())
            {
                count += umap[prefix_sum-k];
            }
            umap[prefix_sum]++;
        }
        return count;
    }
};
```
## First Unique Character in a String
🔗 LeetCode: https://leetcode.com/problems/first-unique-character-in-a-string/
```cpp
class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<int,int>umap;
        for(auto c:s)
        {
            umap[c]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(umap[s[i]]==1)
                return i;
        }
        return -1;
    }
};
```
---

# Sliding Window

## Longest Substring Without Repeating Characters
```cpp
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
```
## Minimum Window Substring
```cpp
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
```
## Fruit Into Baskets
🔗 LeetCode: https://leetcode.com/problems/first-unique-character-in-a-string/

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0,right=0;
        int max_fruits = 0;
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
```
---

# Two Pointer
## 3Sum
🔗 LeetCode: https://leetcode.com/problems/3sum/description/

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(i>0 and nums[i] == nums[i-1])
                continue;
            
            int new_target = -nums[i];
            int left = i+1,right = nums.size()-1;

            while(left<right)
            {
                int sum = nums[left] + nums[right];

                if(sum==new_target)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});

                    while(left<right and nums[left]==nums[left+1])
                        left++;
                    
                     while(left<right and nums[right]==nums[right-1])
                        right--;
                    
                    left++;
                    right--;

                }
                else if(sum<new_target)
                {
                    left++;
                }
                else
                {
                    right--;
                }

            }
        }
        return ans;
        
    }
};
```
## Container With Most Water
🔗 LeetCode: https://leetcode.com/problems/container-with-most-water/description/

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0, right = height.size()-1;
        int curr_water = 0, max_water = INT_MIN;

        while(left<right)
        {
            if(height[left]<=height[right])
            {
                curr_water = height[left] * (right-left);
                left++;
            }
            else
            {
                curr_water = height[right] * (right-left);
                right--;
            }
            max_water = max(max_water,curr_water);
        }
        return max_water;
    }
};
```

## Sort Colors
🔗 LeetCode: https://leetcode.com/problems/sort-colors/description/

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int left = 0,mid = 0,right = nums.size()-1;

        while(mid<=right)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[right]);
                right--;
            }
        }
    }
};
```
## Remove Duplicates from Sorted Array
🔗 LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=1;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i-1] != nums[j])
            {
                nums[i] = nums[j];
                i++;
            }    
        }
        return i;
        
    }
};
```

## Move Zeros
🔗 LeetCode: https://leetcode.com/problems/move-zeroes/description/

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;

        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]!=0)
            {
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};
```

## Two Sum II - Input Array Is Sorted
🔗 LeetCode: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size()-1;

        while(left<right)
        {
            int sum = nums[left] + nums[right];

            if(sum == target)
                return {left+1,right+1};
            else if(sum<target)
                left++;
            else
                right--;
        }
        return {-1,-1};
    }
};
```
---

# Trees
## Lowest Common Ancestor
## 236. Lowest Common Ancestor of a Binary Tree
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==nullptr)
            return nullptr;

        if(root == p || root == q)
        {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p,q);

        if(leftLCA != nullptr and rightLCA != nullptr)
            return root;

        if(leftLCA != nullptr)
            return leftLCA;
        return rightLCA;

    }
};
```
## 235. Lowest Common Ancestor of a Binary Search Tree
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==nullptr)
            return root;

        if(root->val>p->val and root->val>q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val and root->val<q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            return root;
        }
    }
};
```
## 98. Validate Binary Search Tree
```cpp
class Solution {
public:
    bool check_valid(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if(root == nullptr)
            return true;

        if(left!=nullptr and left->val>=root->val)
            return false;
        if(right!=nullptr and right->val<=root->val)
            return false;

        return check_valid(root->left,left,root) and check_valid(root->right,root,right);
    }
    bool isValidBST(TreeNode* root)
    {
        return check_valid(root,nullptr,nullptr);
    }
};
```

---

# Graph
## 133. Clone Graph
```cpp
class Solution {
public:
    unordered_map<Node*,Node*>umap;

    void DFS(Node* node, Node* clone_node)
    {
        for(Node* ngb:node->neighbors)
        {
            if(umap.find(ngb) == umap.end())
            {
                Node* clone = new Node(ngb->val);
                umap[ngb] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(ngb,clone);
            }
            else
            {
                clone_node->neighbors.push_back(umap[ngb]);
            }
        }
    }
    Node* cloneGraph(Node* node)
    {
        if(!node)
            return nullptr;

        Node* clone_node = new Node(node->val);
        umap[node] = clone_node;
        DFS(node,clone_node);

        return clone_node;

    }
};
```
## Number of Islands
```cpp
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isvalid(int nx, int ny, vector<vector<char>>& grid)
    {
        if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and grid[nx][ny]=='1')
            return true;
        return false;
    }
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        grid[x][y]='0';
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isvalid(nx,ny,grid))
            {
                dfs(nx,ny,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    count++;
                }

            }
        }
        return count;
    }
};
```

---

# Stack
## LRU Cache ⭐
## Valid Parenthesis String ⭐
## ===DP SOLUTION====
```cpp
class Solution {
public:
    int dp[101][101];
    bool solve(int i, int opencount, string s)
    {
        if(i==s.size())
            return opencount ==0;

        if(dp[i][opencount]!=-1)
            return dp[i][opencount];

        bool isvalid = false;
        if(s[i] == '(')
            isvalid = solve(i+1,opencount + 1,s);
        else if(s[i] == '*')
        {
            isvalid |= solve(i+1, opencount+1,s);
            isvalid |= solve(i+1,opencount,s);

            if(opencount>0)
                isvalid |= solve(i+1,opencount-1,s);
        }
        else if(opencount>0)
        {
            isvalid |= solve(i+1,opencount-1,s);
        }
        return dp[i][opencount]=isvalid;
    }
    bool checkValidString(string s)
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};
```
## STACK
```cpp
class Solution {
public:
    bool checkValidString(string s)
    {
        stack<int>openst;
        stack<int>astriskst;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                openst.push(i);
            else if(s[i] == '*')
                astriskst.push(i);
            else{
                if(!openst.empty())
                {
                    openst.pop();
                }
                else if(!astriskst.empty())
                {
                    astriskst.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while(!openst.empty() and !astriskst.empty())
        {
            if(openst.top() > astriskst.top())
                return false;

            openst.pop();
            astriskst.pop();
        }
        return openst.empty();
    }
};
```

---

# DFS
## 79. Word Search ⭐
```cpp
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isvalid(int x,int y,int idx,vector<vector<char>>& board,string& word)
    {
        if(x>=0 and x<board.size() and y>=0 and y<board[0].size() and board[x][y] == word[idx])
            return true;
        return false;

    }
    bool dfs(int x,int y,int idx,vector<vector<char>>& board, string& word)
    {
        if(idx == word.size()-1)
            return true;
        board[x][y] = '.';
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isvalid(nx,ny,idx+1,board,word))
            {
                if(dfs(nx, ny, idx+1, board, word))
                    return true;
            }
        }
        board[x][y] = word[idx];
        return false;

    }
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                    if(dfs(i,j,0,board,word))
                        return true;
            }
        }
        return false;;
    }
};
```

---

# Arrays
## 238. Product of Array Except Self ⭐
## 3LOOPS
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int>prefix_mul(nums.size(),1);
        vector<int>suffix_mul(nums.size(),1);
        vector<int>ans(nums.size(),1);

        for(int i=1;i<nums.size();i++)
        {
            prefix_mul[i] = prefix_mul[i-1] * nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix_mul[i] = suffix_mul[i+1] * nums[i+1];
        }
        for(int i=0;i<nums.size();i++)
        {
            ans[i] = prefix_mul[i] * suffix_mul[i];
        }
        return ans;
    }
};
```
## 2LOOPS
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int>ans(nums.size(),1);
        int suffix_mul =1;

        for(int i=1;i<nums.size();i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] = suffix_mul * ans[i];
            suffix_mul = suffix_mul * nums[i];
        }
        return ans;
    }
};
```

---

# Heap
## 23. Merge k Sorted Lists
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;

        while(list1 and list2)
        {
            if(list1->val<=list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1)
        {
            curr->next = list1;
        }
        else
        {
            curr->next = list2;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty())
            return nullptr;

        int i=0;
        while(i<lists.size()-1)
        {
            if(lists.size() == 1)
                return lists[0];

            auto list1 = lists[i++];
            auto list2 = lists[i++];

            lists.push_back(merge2Lists(list1,list2));
        }
        return lists[i];
    }
};
```

---

# Design
## TinyURL (design only)
