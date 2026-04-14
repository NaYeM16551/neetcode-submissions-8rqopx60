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
    private:

     ListNode* reverseList(ListNode* head) {
        if(!head || head->next==NULL)
           return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;

        
    }
      
public:
    void reorderList(ListNode* head) {

        auto slow=head;
        auto fast=slow->next;

        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        auto second=slow->next;
        second=reverseList(second);
        slow->next=nullptr;

        auto first=head;

        while(second)
        {
            auto temp1=first->next;
            auto temp2=second->next;

            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }


        
    }
};
