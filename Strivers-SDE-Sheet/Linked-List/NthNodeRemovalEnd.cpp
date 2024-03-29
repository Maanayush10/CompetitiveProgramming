#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start->next=head;
        ListNode * fast= start;
        ListNode * slow = start;

        for(int i=1; i<=n; ++i)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow= slow->next;
        }
        slow->next= slow->next->next;
        return start->next;//start->next to handle edge case that is 1st node
    }

int main()
{
  //main logic here
  return 0;
}
