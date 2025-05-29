// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Time : O(n)
// Space : O(1)
// Approach 1 : Using length of linked list
 class Solution {
    private:
        int lengthLL(ListNode* head){
            int len = 0;
            if(head == NULL){
                return 0;
            }
    
            while(head != NULL){
                len++;
                head = head->next;
            }
    
            return len;
        }
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int len = lengthLL(head);
    
            int num = len - n + 1;
    
            if(head == NULL || head->next == NULL){
                return NULL;
            }
    
            if(num == 1){
                head = head->next;
                return head;
            }
    
            ListNode* p = head;
            ListNode* temp = head;
            int count = 1;
    
            while(count < num){
                temp = p;
                p = p->next;
                count++;
                if(count == num){
                    temp->next = p->next;
                    delete p;
                }
            }
    
            return head;
        }
    };