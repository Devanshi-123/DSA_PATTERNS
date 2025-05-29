// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
        ListNode* deleteMiddle(ListNode* head) {
            int len = lengthLL(head);
    
            int num = len/2 + 1;
    
            if(head == NULL){
                return NULL;
            }
    
            if(head->next == NULL){
                return NULL;
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