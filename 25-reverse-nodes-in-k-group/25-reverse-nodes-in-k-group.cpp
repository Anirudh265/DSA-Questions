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
    // int h=0;
public:
   
    int lenl(ListNode* head)
    {
        int len=0;
        
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(lenl(head)<k) return head;
        // int iter=len/k;
        int h=0;
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* n;
        int cnt=0;
        while(cur and cnt<k)
        {
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
            cnt++;                
        }
        head->next=reverseKGroup(n,k);
        return prev;
        
    }
};