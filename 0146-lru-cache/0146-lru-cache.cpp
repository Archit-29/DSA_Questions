class LRUCache {   
public:
    class node {
        public:
        int key;
        int value;
        node* next;
        node*prev;

        node(int k, int v){
            key = k;
            value = v;
            next= NULL;
            prev= NULL;
        } 
    };

    unordered_map<int,node*>mp;
    int size;
    node* head= new node(-1,-1);
    node* tail = new node(-1,-1);

    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(node*curr){
        mp.erase(curr->key);
        node*front= curr->next;
        node*back = curr->prev;
        back->next=front;
        front->prev=back;
    }

    void insertNode(node*newNode){
        mp[newNode->key]=newNode;
        node* headNext= head->next;
        newNode->next=headNext;
        head->next=newNode;
        newNode->prev=head;
        headNext->prev=newNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node*temp= mp[key];
            int val= temp->value;
            deleteNode(temp);
            insertNode(temp);
            return val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node*node=mp[key];
            deleteNode(node);
        }
        if(mp.size()>=size){
            deleteNode(tail->prev);
        }
        insertNode(new node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */