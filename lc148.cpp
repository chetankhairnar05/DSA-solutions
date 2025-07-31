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
    ListNode* sortList(ListNode* head) {
        if(!head){
            return NULL;
        }
        vector<int>v;
        auto cur = head;
        while(cur){
            v.push_back(cur->val);
            cur = cur->next;
        }
        sort(v.begin(),v.end());
        ListNode* head2 = new ListNode(v[0]);
        cur = head2;
        for(int i  = 1;i<v.size();i++){
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }
        return head2;

    }
};