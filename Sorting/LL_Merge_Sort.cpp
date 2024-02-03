struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;

    // Split the list into two halves
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr; // Split the list

    // Recursively sort the two halves and merge them
    return merge(mergeSort(head), mergeSort(secondHalf));
}