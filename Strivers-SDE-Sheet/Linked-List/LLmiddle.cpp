#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


//bruteforce
ListNode* middleNode(ListNode* head) {
        int count=0;
        int mid=0;
        ListNode * dummy=head;
        while(dummy!=NULL)
        {
            count++;
            dummy= dummy->next;
        }
        mid= (count/2)+1;
        dummy= head;
        count=1;
        while(count<mid)
        {
            dummy= dummy->next;
            count++;
        }
        return dummy;
    }


//optimal
   ListNode* middleNode2(ListNode* head) {
        ListNode * fast= head, *slow =head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
int main(){
  //main logic here
  return 0;
}
