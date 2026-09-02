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
    ListNode* reverseList(ListNode* head) {
        //using 3 pointer 
        ListNode*curr=head;
        if(!head){
            return head;
        }
        ListNode*fut=head->next;
        ListNode*prev=NULL;
        while(fut){
            curr->next=prev;
            prev=curr;
            curr=fut;
            fut=fut->next;
        }
        curr->next=prev;
        return curr;

    }
};