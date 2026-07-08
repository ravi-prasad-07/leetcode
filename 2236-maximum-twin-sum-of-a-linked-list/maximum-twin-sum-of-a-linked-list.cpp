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
    int pairSum(ListNode* head) {
        int n=0, ans=0;
        ListNode* temp=head;

        ListNode* fake=nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }

        for(int i=0; i<n/2; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        fake=curr;

        for(int i=0; i<n/2; i++){
            int temp=prev->val + fake->val;
            ans=max(ans, temp);
            prev=prev->next;
            fake=fake->next;
        }

        return ans;

    }
};