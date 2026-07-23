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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k == 0) 
            return head;

        int ll_size = 0;
        ListNode* node = head;
        while(node)
        {
            node = node->next;
            ll_size++;
        }

        k = k%ll_size;
        if(k==0)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<k;i++)
        {
            fast = fast->next;
        }

        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};