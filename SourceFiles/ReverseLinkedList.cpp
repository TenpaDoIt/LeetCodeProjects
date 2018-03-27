//      LeetCode Problem 206 :
/*
Reverse a singly linked list.
*/
#include "../HeaderFiles/ReverseLinkedList.hpp"

ListNode* ReverseLinkedList::reverseList(ListNode* head)
{
    ListNode *ResultListNode;
        if (head != NULL)
        {
            ResultListNode = new ListNode(head->val);
            head = head->next; 
        }
        while (head != NULL)
        {
            ListNode *CurrentPos = new ListNode(head->val);
		    CurrentPos->next = ResultListNode;
		    ResultListNode = CurrentPos;

            head = head->next;
        }

        return ResultListNode;
}    

ListNode* ReverseLinkedList::reverseList2(ListNode* head)
{
    ListNode *ResultListNode = head, *reverseNodePos = head;
    if (reverseNodePos != NULL)
    {
        reverseNodePos = reverseNodePos->next;
        head = reverseNodePos;
        ResultListNode->next = NULL;
    }
    while (reverseNodePos != NULL)
    {
        reverseNodePos = reverseNodePos->next;
        head->next = ResultListNode;
        ResultListNode = head;
        head = reverseNodePos;
    }

    return ResultListNode;
}  

void ReverseLinkedList::Test()
{
    srand(time(NULL));

	ListNode *TestA = new ListNode(rand() % 10), *Temp;
    for (int i = 0; i < 4; i++)
	{
		ListNode *CurrentPos = new ListNode(rand() % 10);
		CurrentPos->next = TestA;
		TestA = CurrentPos;
	}
    Temp = TestA;
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
	std::cout << "\n";

    Temp = reverseList2(TestA);
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
}