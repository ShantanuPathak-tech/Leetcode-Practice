/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Brute force using map with O(n * 2 logn) T.C
        //  map<ListNode*, int> mpp;
        //  ListNode *temp = head;

        // while(temp != NULL){
        //     if(mpp.find(temp) != mpp.end()){
        //         return temp;
        //     }
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // return NULL;

        // Optimal Approach using slow and fast
        //T.C = O(N), S.C = O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};