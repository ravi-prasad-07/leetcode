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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* leftPrev=&dummy;

        for(int i=0; i<left-1; i++){
            leftPrev=leftPrev->next;
        }

        ListNode* curr=leftPrev->next;
        ListNode* prev=nullptr;

        for(int i=0; i<=right-left; i++){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        leftPrev->next->next=curr;
        leftPrev->next=prev;

        return dummy.next;
    }
};