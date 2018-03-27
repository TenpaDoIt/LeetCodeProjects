#include <stdlib.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class ReverseLinkedList
{
public:
    ListNode* reverseList(ListNode* head);  
    ListNode* reverseList2(ListNode* head);  
    void Test();
};