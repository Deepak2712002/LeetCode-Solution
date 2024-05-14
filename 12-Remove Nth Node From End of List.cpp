class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    for (int i = 0; i < n + 1; i++) {
        if (second == nullptr) return nullptr; 
        second = second->next;
    }
    
    while (second != nullptr) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node
    ListNode* temp = first->next;
    first->next = first->next->next;
    delete temp;
    
    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);

    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);

    int n1 = 2, n2 = 1, n3 = 1;

    cout << "Original list 1: ";
    printList(head1);
    std::cout << "Modified list 1: ";
    printList(removeNthFromEnd(head1, n1));

    cout << "Original list 2: ";
    printList(head2);
    cout << "Modified list 2: ";
    printList(removeNthFromEnd(head2, n2));

    cout << "Original list 3: ";
    printList(head3);
    cout << "Modified list 3: ";
    printList(removeNthFromEnd(head3, n3));

    return 0;
}
};
