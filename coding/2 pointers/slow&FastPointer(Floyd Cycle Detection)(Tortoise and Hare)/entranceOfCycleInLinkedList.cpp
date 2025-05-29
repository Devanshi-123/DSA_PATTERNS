// https://leetcode.com/problems/linked-list-cycle-ii/submissions/1620163250/

// // Time : O(n)
// // Space : O(1)

ListNode *detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    if(fast != slow){
        return NULL;
    }

    slow = head;
    cout << fast->val << endl;

    while(slow != NULL && fast != NULL && slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return fast;

}