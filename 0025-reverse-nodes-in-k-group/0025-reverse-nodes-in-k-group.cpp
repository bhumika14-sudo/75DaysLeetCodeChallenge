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
    // Reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }   

    ListNode* findKnode(ListNode* head, int k){
        while(head && --k){
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
       
        while(temp != NULL){
            ListNode* kth = findKnode(temp, k);

            // if k nodes are not there
            if (kth == NULL) {

                if (prev != NULL)
                    prev->next = temp;

                break;
            }
            ListNode* nxtGrp = kth->next;
            kth->next = NULL; // detach the grp

            ListNode* newHead = reverse(temp);
            temp->next = nxtGrp;

            if(temp==head){ // update the head of reversed LL
                head = newHead;
            }
            else{
                prev->next = newHead;
            }
            prev = temp;
            temp = nxtGrp;
        }
        return head; 
    }
};