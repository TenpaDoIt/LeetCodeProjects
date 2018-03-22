// 		LeetCode Problem 2 :
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include "../HeaderFiles/AddTwoNumbers.hpp"

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *ln1 = l1, *ln2 = l2, *Result, *currentPos = new ListNode(0);
	Result = currentPos;
	int tempN, NTens = 0, NOnes, val1, val2;
	while (ln1 != NULL || ln2 != NULL || NTens != 0) {
		val1 = (ln1 == NULL) ? 0 : ln1->val;
		val2 = (ln2 == NULL) ? 0 : ln2->val;
		tempN = val1 + val2 + NTens;

		NOnes = tempN % 10;
		NTens = (tempN > 9) ? 1 : 0;

		currentPos->next = new ListNode(NOnes);
		currentPos = currentPos->next;

		ln1 = (ln1 == NULL) ? NULL : ln1->next;
		ln2 = (ln2 == NULL) ? NULL : ln2->next;
	}
	return Result->next;
}

void AddTwoNumbers::Test()
{
	srand(time(NULL));

	ListNode *Head1 = new ListNode(rand() % 10), *Head2 = new ListNode(rand() % 10), *Temp, *CurrentPos;

	CurrentPos = Head1;
	for (int i = 0; i < 1; i++)
	{
		ListNode *CurrentPos = new ListNode(rand() % 10);
		CurrentPos->next = Head1;
		Head1 = CurrentPos;
	}
	Temp = Head1;
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
	std::cout << "\n";

	CurrentPos = Head2;
	for (int i = 0; i < 1; i++)
	{
		ListNode *CurrentPos = new ListNode(rand() % 10);
		CurrentPos->next = Head2;
		Head2 = CurrentPos;
	}
	Temp = Head2;
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
	std::cout << "\n";

	Temp = addTwoNumbers(Head1, Head2);
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
}
