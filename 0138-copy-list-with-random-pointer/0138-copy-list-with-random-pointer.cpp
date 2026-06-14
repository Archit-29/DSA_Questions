/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void createCopy(Node*head){
        Node*temp=head;
        while(temp){
            Node*copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
    }

    void  connectRandomPointer(Node*head){
        Node*temp=head;
        while(temp){
            Node*copy=temp->next;
            if(temp->random) copy->random=temp->random->next;
            else copy->random=NULL;
            temp=temp->next->next;
        }
    }

    Node*copyList(Node*head){
        Node*dummy= new Node(0);
        Node*res=dummy;
        Node*temp=head;

        while(temp){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        createCopy(head);
        connectRandomPointer(head);
        return copyList(head);
    }
};