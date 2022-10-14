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
    ListNode* middle(ListNode* &head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast!=nullptr and fast->next!=nullptr)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        return prev;
        
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or !head->next) return nullptr;
        ListNode* prev=middle(head);
        prev->next=prev->next->next;
        return head;
        
        
        
    }
};