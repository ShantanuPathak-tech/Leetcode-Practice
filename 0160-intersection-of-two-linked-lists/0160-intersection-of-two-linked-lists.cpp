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

ListNode *collisionPoint(ListNode *tempA, ListNode *tempB, int d){
    while(d){
        d--;
        tempB = tempB->next;
    }
    while(tempA != tempB){
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return tempA;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //First Approach
        // ListNode *temp1 = headA;
        // int N1 = 0;
        // while(temp1 != NULL){
        //     N1++;
        //     temp1 = temp1->next;
        // }
        // ListNode *temp2 = headB;
        // int N2 = 0;
        // while(temp2 != NULL){
        //     N2++;
        //     temp2 = temp2->next;
        // }
        // if(N1 < N2){
        //     return collisionPoint(headA, headB, N2-N1);
        // }
        // else{
        //     return collisionPoint(headB, headA, N1-N2);
        // }

        //Optimal Approach
        //T.C = O(N1 + N2) where N1 and N2 are size of LL A and B
        //S.C = O(1)
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2) return temp1;
            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }
        return temp1;
    }
};