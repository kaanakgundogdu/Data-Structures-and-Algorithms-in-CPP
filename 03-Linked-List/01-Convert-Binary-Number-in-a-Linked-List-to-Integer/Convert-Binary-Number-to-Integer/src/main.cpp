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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* a = head;
        std::vector<int> vec;
        int p = 0;
        int answer = 0;
        while (a) {
            vec.push_back(a->val);
            a = a->next;
        }
        p = vec.size() - 1;
        for (int i = 0; i < vec.size(); i++) {
            answer += vec[i] * std::pow(2, p);
            p--;
        }
        return answer;
    }
};


int main()
{
    ListNode *head = new ListNode(1);
    ListNode* sec = new ListNode(0);
    ListNode* third = new ListNode(1);

    head->next = sec;
    sec->next = third;

    ListNode* head2 = new ListNode();

    Solution s;
    std::cout << s.getDecimalValue(head) << "\n";
    std::cout << s.getDecimalValue(head2) << "\n";
    std::cout << "Hello World!\n";
    delete head;
    delete sec;
    delete third;
    delete head2;
}
