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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* res=new ListNode();
        ListNode* ans=res;

        while(temp!=nullptr){
            if(temp->next!=nullptr && temp->val==temp->next->val){
                int num=temp->val;
                while(temp!=nullptr && num==temp->val){
                    temp=temp->next;
                }
            }
            else{
                res->val=temp->val;
                res->next=new ListNode();
                res=res->next;
                temp=temp->next;
            }
        }

        ListNode* boss=ans;

        if(boss->next==nullptr){
            delete boss;
            return nullptr;
        }

        while(boss!=nullptr){
            if(boss->next->next==nullptr){
                delete boss->next;
                boss->next=nullptr;
                break;
            }
            boss=boss->next;
        }

        return ans;

    }
};