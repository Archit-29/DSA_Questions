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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        int sum=0;
        vector<int>nums;

        while(l1!=NULL && l2!=NULL){
            if(flag==1)  {
                sum=l1->val+l2->val+1;
                flag=0;
            }
            else sum=l1->val+l2->val;

            if(sum>=10){
               flag=sum/10;
                sum=sum%10;
            }
            nums.push_back(sum);
            l1=l1->next;
            l2=l2->next;
        }
        sum=0;
        while(l1!=NULL){
           if(flag==1){
            sum=l1->val+1;
                if(sum>=10){
                    flag=sum/10;
                    sum=sum%10;
                    nums.push_back(sum);
                }
                else nums.push_back(sum);
           }else{
            nums.push_back(l1->val);
           }
           l1=l1->next;
        }
            sum=0;
         while(l2!=NULL){
            if(flag==1){
            sum=l2->val+1;
                if(sum>=10){
                    flag=sum/10;
                    sum=sum%10;
                    nums.push_back(sum);
                }
                else nums.push_back(sum);
           }else{
            nums.push_back(l2->val);
           }
           l2=l2->next;
        }

        ListNode*start=new ListNode();
        ListNode*dummy=start;
       for(int i=0;i<nums.size();i++){
            ListNode*temp=new ListNode();
            temp->val=nums[i];
            dummy->next=temp;
            dummy=temp;
       }

       if(flag==1){
        ListNode*temp=new ListNode();
        temp->val=1;
        dummy->next=temp;
        dummy=temp;
       }
       return start->next;
    }
};