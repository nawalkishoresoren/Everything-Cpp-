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

## Contiguous Array
🔗 LeetCode: https://leetcode.com/problems/contiguous-array/description/
```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int>umap;
        umap[0] = -1;
        int sum = 0, max_arr = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                sum += 1;
            else
                sum -= 1;

            if(umap.find(sum) == umap.end())
                umap[sum] = i;
            else
                max_arr = max(max_arr,i - umap[sum]);
        }
        return max_arr;
    }
};
```

## Subarray Sums Divisible by K
🔗 LeetCode: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int>umap;
        umap[0]++; 
        int sum = 0, count = 0, remainder = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            remainder = sum % k;
            if(remainder<0)
                remainder += k;
            
            count += umap[remainder];
            umap[remainder]++;
        }
        return count;
    }
};
```

## Valid Sudoku
🔗 LeetCode: https://leetcode.com/problems/valid-sudoku/description/
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<char>rows[9];
        unordered_set<char>columns[9];
        unordered_set<char>grids[9];

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                    continue;
                else{
                    int grid_no = (i/3)*3 + (j/3);

                    if(rows[i].find(board[i][j]) != rows[i].end())
                        return false;
                    if(columns[j].find(board[i][j]) != columns[j].end())
                        return false;
                    if(grids[grid_no].find(board[i][j]) != grids[grid_no].end())
                        return false;

                    rows[i].insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                    grids[grid_no].insert(board[i][j]);
                }
            }
        }
        return true;
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

## Longest Repeating Character Replacement
🔗 LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/description/
```cpp
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
```

## Minimum Size Subarray Sum
🔗 LeetCode: https://leetcode.com/problems/minimum-size-subarray-sum/description/
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left = 0, right = 0, sum = 0;
        int res = INT_MAX;

        while(right<nums.size())
        {
            sum += nums[right];

            while(sum>=target)
            {
                res = min(res, right - left + 1);

                sum -= nums[left];
                left++;
            }
            right++;

        }
        return res == INT_MAX ? 0 : res;
        
    }
};
```

## Max Consecutive Ones III
🔗 LeetCode: https://leetcode.com/problems/max-consecutive-ones-iii/description/
```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int left = 0, zeros = 0, ans = 0, res = 0;

        for(int right = 0;right<nums.size();right++)
        {
            if(nums[right]==0)
                zeros++;
            
            while(zeros > k)
            {
                if(nums[left]==0)
                    zeros--;
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};
```

## Permutation in String
🔗 LeetCode: https://leetcode.com/problems/permutation-in-string/description/
```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(auto c: s1)
        {
            freq1[c-'a']++;
        }
        
        int left = 0;
        for(int right =0;right<s2.size();right++)
        {
            freq2[s2[right]-'a']++;

            if(right-left+1 > s1.size())
            {
                freq2[s2[left]-'a']--;
                left++;
            }
            if(right-left+1 == s1.size())
                if(freq1==freq2)
                    return true;
                
        }
        return false;
    }
};
```

## Find All Anagrams in a String
🔗 LeetCode: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
```cpp
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

## Trapping Rain Water
🔗 LeetCode: https://leetcode.com/problems/trapping-rain-water/description/

```cpp
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int res = 0;
        int left = 0, right = height.size()-1; 
        int maxleft = height[left], maxright = height[right];


        while(left<right)
        {
            if(maxleft<=maxright)
            {
                res += (maxleft - height[left]);
                left++;
                maxleft = max(maxleft,height[left]);
            }
            else
            {
                res += (maxright - height[right]);
                right--;
                maxright = max(maxright,height[right]);
            }
        }
        return res; 
    }
};
```
## Valid Palindrome
🔗 LeetCode: https://leetcode.com/problems/valid-palindrome/description/

```cpp
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0, right = s.size()-1;

        while(left<right)
        {
            while(left<right and !isalnum(s[left]))
                left++;
            
            while(left<right and !isalnum(s[right]))
                right--;
            
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            
            left++;
            right--;
        }

        return true;
        
    }
};
```
## Reverse String
🔗 LeetCode: https://leetcode.com/problems/reverse-string/description/

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int left = 0, right = s.size()-1;

        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
```

## Squares of a Sorted Array
🔗 LeetCode: https://leetcode.com/problems/squares-of-a-sorted-array/description/

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int left = 0, right = nums.size()-1;
        vector<int>ans;

        while(left<=right)
        {
            if(pow(nums[left], 2) <= pow(nums[right], 2))
            {
                ans.push_back(pow(nums[right], 2));
                right--;
            }
            else
            {
                ans.push_back(pow(nums[left], 2));
                left++;
            }
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
```
---

# Binary Search
## Search in Rotated Array
🔗 LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size()-1;

        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return mid;
            
            if(nums[left]<=nums[mid])
            {
                //LEFT HALF IS SORTED
                if(nums[left]<=target and target<nums[mid])
                {
                    //TARGET PRESENT IN THIS PART
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
            else
            {
                //RIGHT HALF IS SORTED.
                if(nums[mid]<target and target<=nums[right])
                {
                    //TARGET PRESENT IN THIS PART
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};
```

## Koko Eating Bananas
🔗 LeetCode: https://leetcode.com/problems/koko-eating-bananas/description/
```cpp
class Solution {
public:
    long long time(int speed, vector<int>& piles)
    {
        long long total_time = 0;
        for(auto pile:piles)
        {
            if(pile%speed == 0)
                total_time += pile/speed;
            else
                total_time += (pile/speed)+1;
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1,right = 0;
        for(auto pile:piles)
        {
            right = max(right,pile);
        }

        int min_time = right;
        while(left<=right)
        {
            int mid = left + ( right - left)/2;

            if(time(mid,piles)<=h)
            {
                min_time = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return min_time;
    }
};
```
## Capacity To Ship Packages Within D Days
🔗 LeetCode: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
```cpp
class Solution {
public:
    bool check(int curr_capacity, vector<int>& weights, int days) {
        int total_days = 1; 
        int temp = 0;

        for (int w : weights) {
            if (w > curr_capacity) return false;

            if (temp + w > curr_capacity) {
                total_days++; 
                temp = w;     
            } else {
                temp += w;
            }
        }
        return total_days <= days; 
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = 1,right = 0;

        //CALCULATING THE RIGHT.
        for(auto weight:weights)
        {
            right += weight;
        }

        int mini_capacity = right; //THIS CAPACITY WILL ALWAYS WORK.

        //DOING BINARY SEARCH ON ANSWER(RANAGE {LEFT,RIGHT})
        while(left<=right)
        {
            int mid = left + (right - left)/2;

            if(check(mid,weights,days))
            {
                mini_capacity = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return mini_capacity;
    }
};
```

---

# Linked List ⭐⭐⭐⭐⭐
## Reverse Linked List
🔗 LeetCode: https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        while(head)
        {
            ListNode* next_element = head->next;
            head->next = prev;
            prev = head;
            head = next_element;
        }
        return prev;
    }
};
```

## Middle of the Linked List
🔗 LeetCode: https://leetcode.com/problems/middle-of-the-linked-list/description/
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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```

## Linked List Cycle
🔗 LeetCode: https://leetcode.com/problems/linked-list-cycle/description/
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }
        return false;
    }
};
```

## Merge Two Sorted Lists
🔗 LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;

        while(list1 and list2)
        {
            if(list1->val<list2->val)
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
            curr->next = list1;
        else
            curr->next = list2;

        return ans->next;
    }
};
```
## Merge k Sorted Lists
🔗 LeetCode: https://leetcode.com/problems/merge-k-sorted-lists/description/
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

## Diameter of Binary Tree
🔗 LeetCode: https://leetcode.com/problems/valid-sudoku/description/
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, int &max_diameter)
    {
        if(root == nullptr)
            return 0;

        int left_height = height(root->left,max_diameter);
        int right_height = height(root->right,max_diameter);

        max_diameter = max(max_diameter,left_height + right_height);
        return 1 + max(left_height,right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int max_diameter = INT_MIN;
        height(root,max_diameter);
        return max_diameter;
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
## Valid Parenthesis String ⭐
### ===DP SOLUTION====
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
### ===STACK SOLUTION====
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
## Merge k Sorted Lists
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
## Top K Frequent Elements
🔗 LeetCode: https://leetcode.com/problems/top-k-frequent-elements/description/
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

        for(auto pair_p:umap)
        {
            pq.push({pair_p.second,pair_p.first});

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

## K Closest Points to Origin
🔗 LeetCode: https://leetcode.com/problems/k-closest-points-to-origin/
```cpp
class Solution {
public:
    class compare{
        public:
        bool operator()(vector<int>a,vector<int>b)
        {
            int dist_a = a[0] * a[0] + a[1] * a[1];
            int dist_b = b[0] * b[0] + b[1] * b[1];

            return dist_a < dist_b;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(auto point : points)
        {
            pq.push(point);

            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;    
    }
};
```
---

# Recurssion/DP

## Climbing Stairs
🔗 LeetCode: https://leetcode.com/problems/climbing-stairs/description/
```cpp
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int>dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
```
## Longest Increasing Subsequence
🔗 LeetCode: https://leetcode.com/problems/longest-increasing-subsequence/
```cpp
class Solution {
public:
    int solve(vector<int>& nums,int i, int p, vector<vector<int>>&dp)
    {
        if(i>=nums.size())
            return 0;
        
        if(p!=-1 and dp[i][p] != -1)
            return dp[i][p];
        int take = 0;

        if(p == -1 or nums[i] > nums[p])
        {
            take = 1 + solve(nums,i+1,i,dp);
        }
            
        int skip = solve(nums,i+1,p,dp);

        if(p!=-1)
            return dp[i][p]=max(skip,take);
        return max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};
```
## House Robber
🔗 LeetCode: https://leetcode.com/problems/house-robber/
```cpp
class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>&dp)
    {
        if(idx>=nums.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];

        int steal = nums[idx] + solve(idx+2,nums,dp);
        int skip = solve(idx+1,nums,dp);

        return dp[idx] = max(steal,skip);
    }

    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size()+1, -1);
        return solve(0,nums,dp);
    }
};
```
## Coin Change
🔗 LeetCode: https://leetcode.com/problems/coin-change/
```cpp
class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount,vector<vector<int>>&dp)
    {
        if(amount == 0)
            return 0;
        
        if(amount<0 || idx<0)
            return 1e9;

        int take = 1e9;

        if(dp[idx][amount]!= -1)
            return dp[idx][amount];

        if(coins[idx]<=amount)
        {
            take = 1 + solve(idx,coins,amount - coins[idx],dp);
        }
        int skip = solve(idx-1,coins,amount,dp);
        
        return dp[idx][amount] = min(take,skip);

    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1, -1));
        int ans =  solve(coins.size()-1,coins,amount,dp);
        return ans==1e9?-1:ans;
    }
};
```

## Coin Change II
🔗 LeetCode: https://leetcode.com/problems/coin-change/
```cpp
class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>&dp)
    {
        if(amount == 0)
            return 1;
        
        if(idx==coins.size())
            return 0;
        
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];

        if(coins[idx]>amount)
        {
            return dp[idx][amount] = solve(idx+1,coins,amount,dp);
        }
        int take = solve(idx,coins,amount - coins[idx],dp);
        int skip = solve(idx+1,coins,amount,dp);

        return dp[idx][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount + 1,-1));
        return solve(0,coins,amount,dp);
        
    }
};
```
---

# Bit Manipulation
## Single Number
🔗 LeetCode: https://leetcode.com/problems/single-number/
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int result = 0;
        for(auto num:nums)
        {
            result ^= num;
        }
        return result;
    }
};
```

## Counting Bits
🔗 LeetCode: https://leetcode.com/problems/counting-bits/description/
```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        int offset = 1;
        for(int i=1;i<=n;i++)
        {
            if(offset * 2 == i)
            {
                offset = i;
            }
            dp[i] = 1+dp[i-offset];
        }
        return dp;
    }
};
```

## Reverse Bits
🔗 LeetCode: https://leetcode.com/problems/reverse-bits/description/
```cpp
class Solution {
public:
    int reverseBits(int n) 
    {
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            ans<<=1;
            if((n&1)==1)
            {
                ans++;
            }
            n>>=1;
        }
        return ans;
    }
};
```
---
# Backtracking
## Subsets
🔗 LeetCode: https://leetcode.com/problems/subsets/description/
```cpp
class Solution {
public:
    vector<vector<int>>result;
    void solve(int i,vector<int>&nums, vector<int>&temp)
    {
        if(i>=nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int>temp;
        solve(0,nums,temp);
        return result;
    }
};
```

## Permutations
🔗 LeetCode: https://leetcode.com/problems/permutations/
```cpp
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx, vector<int>& nums)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        solve(0,nums);
        return ans;
    }
};
```
## Combination Sum
🔗 LeetCode: https://leetcode.com/problems/combination-sum/description/
```cpp
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int idx,vector<int>& candidates, vector<int>& temp, int target)
    {
        if(idx==candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[idx]<=target)
        {
            temp.push_back(candidates[idx]);
            solve(idx,candidates,temp,target - candidates[idx]);
            temp.pop_back();
        }
        solve(idx+1,candidates,temp,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>temp;
        solve(0,candidates,temp,target);
        return ans;
    }
};
```
## Word Search
🔗 LeetCode: https://leetcode.com/problems/word-search/
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