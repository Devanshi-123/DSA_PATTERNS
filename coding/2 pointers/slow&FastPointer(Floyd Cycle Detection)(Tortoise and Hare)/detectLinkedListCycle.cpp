// https://leetcode.com/problems/linked-list-cycle/submissions/1620077062/

// Time : O(n)
// Space : O(1)

bool hasCycle(ListNode *head) {
    // base case 
    if(head == NULL){
        return false;
    }

    if(head->next == NULL){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }

    return false;

}