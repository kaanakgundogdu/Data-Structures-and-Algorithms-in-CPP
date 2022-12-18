#include <iostream>
#include<vector>
#include<cmath>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* reverse_ll(ListNode *head) {
    ListNode* current_node = head;
    ListNode* prev = NULL;


    while (current_node)
    {
        ListNode* next_node = current_node->next;
        current_node->next = prev;
        prev = current_node;
        current_node= next_node;
    }
    return prev;

}


void print_ll(ListNode* head) {
    ListNode* current_node = head;

    while (current_node)
    {
        std::cout << current_node->val << " ";
        current_node = current_node->next;
    }
    std::cout << "\n";
}


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* sec = new ListNode(2);
    ListNode* third = new ListNode(3);

    head->next = sec;
    sec->next = third;

    print_ll(head);

    ListNode*  s= reverse_ll(head);
    print_ll(s);

    delete head;
    delete sec;
    delete third;
}
