#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return head;

        struct ListNode *curr = head->next ? head->next : NULL;
        struct ListNode *prev = head;
        
        while(curr)
        {
            if(prev->val > curr->val)
            {
                prev->next = curr->next;
                curr->next = head;
                head = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};