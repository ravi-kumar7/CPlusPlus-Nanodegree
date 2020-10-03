#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(NULL) {}
};

friend bool operator < (const TreeNode* &l, const TreeNode* &r) {
        return l->val < r->val;
    }