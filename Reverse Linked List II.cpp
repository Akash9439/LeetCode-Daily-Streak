/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]*/
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
class Solution {
public:
    
    
    ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL, *next = NULL, *current = head;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
        
        return prev;
      }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    
         ListNode* current = head, *prev = NULL;
         int count=1;
        while(count != left){
             prev = current;
             current = current->next;
             count++;
         }
        
        ListNode* start = current;
       while(count != right){
           current = current->next;
         count++;
        }
        
      ListNode* rest = current->next;
     current->next = NULL;
        
         ListNode* newHead = reverse(start);
         if (prev!=NULL){
           prev->next = newHead;

         }
        current = newHead;
        while(current->next!=NULL){
            current= current->next;
        }
        current->next = rest;
        if(left == 1){
            return newHead;}
       else{
           return head;
        }
    }
};
