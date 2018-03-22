#include <stdlib.h>
#include <time.h>
#include <iostream>

// AddTwoNumbers.cpp : Defines the entry point for the console application.
//
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode(int x) : val(x), next(NULL) {}
    };

class AddTwoNumbers {
    
public:
    AddTwoNumbers(){};
	~AddTwoNumbers(){};
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	void Test();
};