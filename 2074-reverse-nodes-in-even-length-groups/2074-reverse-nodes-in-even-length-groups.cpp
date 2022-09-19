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
    ListNode* reverse(ListNode* head,int k)
    {
        if(!head or !head->next) return head;
        
        ListNode* cur = head, *tail = head;
        int len = 0;
        
        while(cur && len < k) {
            tail = cur;
            cur = cur->next;
            len++;
        }
        cout<<len<<" ";
        if(len%2==0)
        {
            int cnt=len;
            ListNode* prev=nullptr,*cur=head,*n;
            while(cur and cnt--)
            {
                n=cur->next;
                cur->next=prev;
                prev=cur;
                cur=n;
            }
            
            head->next=reverse(n,len+1);
            return prev;
        }
        tail->next=reverse(cur,len+1);
        return head;        
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(!head or !head->next) return head;
        return reverse(head,1);
        
    }
};