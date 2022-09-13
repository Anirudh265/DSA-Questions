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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head,*end=head;
        while(k>1)
        {
            fast=fast->next;k--;
        }
        ListNode* start=fast;
        while(fast->next)
        {
            end=end->next;
            fast=fast->next;
        }
        swap(start->val,end->val);
        return head;   
    }
};