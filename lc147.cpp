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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        while(cur){
            ListNode* min = cur;
            ListNode* it = cur->next;
            while(it){
                if(it->val<min->val){
                    min = it;
                }
                it = it->next;
            }
            swap(cur->val,min->val);

            cur = cur->next;
        }
        return head;
    }
};