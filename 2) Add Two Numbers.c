//https://leetcode.com/problems/add-two-numbers/

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

//C Solution

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL; // Pointer to the result list
    struct ListNode* tail = NULL; // Pointer to the end of the result list
    int carry = 0; // Carry value for addition
    
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        if (result == NULL) {
            result = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        carry = sum / 10;
    }
    return result;
}
