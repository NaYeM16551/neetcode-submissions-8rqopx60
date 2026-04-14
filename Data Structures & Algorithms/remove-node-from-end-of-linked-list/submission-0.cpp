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

    int length(ListNode*head)
    {
        if(!head)
         return 0;
        return 1+length(head->next);
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        n=length(head)-n+1;
        if(n==1)
          return head->next;

        auto temp=head;
        auto dummy=new ListNode(-1);

        int number_of_nodes=1;

        

        while(number_of_nodes!=n)
        {
            number_of_nodes++;

            dummy=temp;
            temp=temp->next;
        }

        auto link=temp->next;
        dummy->next=link;
        temp->next=nullptr;

        return head;

        
        
    }
};
