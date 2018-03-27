#include <stdlib.h>
#include <iostream>
#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
#endif /* STRUCT_LISTNODE */

class ReverseLinkedList
{
public:
    ListNode* reverseList(ListNode* head);  
    ListNode* reverseList2(ListNode* head);  
    void Test();
};