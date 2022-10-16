//leetcode.com/problems/add-two-numbers
// Here are two methods to solve this problem
// 1) Iterative
// 2) Recursive

// Iterative: Here we keep iterating through both linked lists and summing the numbers we get.
// If there is a carry then store it in a variable and add it to next iteration
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1),*ans=head;
        int carry=0;
        while(l1 || l2){
            int d1=0,d2=0;
            if(l1) d1=l1->val,l1=l1->next;
            if(l2) d2=l2->val,l2=l2->next;
            d1+=(d2+carry);
            carry=d1/10,d1%=10;

            if(head->val==-1)head->val=d1;
            else {
                head->next=new ListNode(d1);
                head=head->next;
            }
        }
        if(carry!=0)head->next=new ListNode(carry);
        return ans;
    }
};
// TC: O(max(size of l1, size of l2))

// Recursive: Here we do the same logic but with recusion.
class Solution {
public:
    ListNode* helper(ListNode* l1, ListNode* l2,int carry){
        if(!l1 && !l2 && !carry)return nullptr;
        if(!l1 && !carry)return l2;
        if(!l2 && !carry)return l1;
        
        int s=carry;
        if(l1)s+=l1->val; if(l2)s+=l2->val;
        carry=s/10;

        ListNode *ans=new ListNode(s%10);
        ans->next=helper(l1?l1->next:nullptr,l2?l2->next:nullptr,carry);
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1,l2,0);
    }
};
// TC: O(max(size of l1,size of l2))
