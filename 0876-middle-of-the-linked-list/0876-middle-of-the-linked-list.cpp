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
    ListNode* middleNode(ListNode* head) {
        // Brute force
        // T.C = O(n + n/2)
        //  ListNode *temp = head;
        //  int cnt = 0;
        //  while(temp != NULL){
        //      cnt++;
        //      temp = temp->next;
        //  }
        //  temp = head;
        //  int midEle = (cnt / 2) + 1;
        //  while(temp != NULL){
        //      midEle--;
        //      if(midEle == 0){
        //          break;
        //      }
        //      temp = temp->next;
        //  }
        //  return temp;

        // Optimal Aprroach Tortoise and Hare algo
        //T.C = O(n/2), S.C = O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};