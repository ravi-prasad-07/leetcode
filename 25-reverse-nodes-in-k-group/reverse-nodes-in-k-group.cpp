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

    void reverse(ListNode* pre, ListNode* head, int k){
        ListNode* Tprev = nullptr;
        ListNode* Tcurr = head;
        ListNode* Tnext = nullptr;
        int count = 0;

        while(count < k && Tcurr != nullptr){
            Tnext = Tcurr->next;
            Tcurr->next = Tprev;
            Tprev = Tcurr;
            Tcurr = Tnext;
            count++;
        }

        pre->next = Tprev;
        head->next = Tcurr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1){
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(true){

            ListNode* temp = prev;
            for(int i = 0; i < k; i++){
                temp = temp->next;
                if(temp == nullptr) return dummy.next;
            }

            ListNode* groupHead = prev->next;
            reverse(prev, groupHead, k);

            prev = groupHead;
        }
    }
};