class Node{
    public:
    int key;
    int val;
    int count;
    Node*next;
    Node*prev;
    Node(int k, int v){
        key=k;
        val=v;
        count=1;
    }
};

class List {
    public:
    int len;
    Node* head;
    Node*tail;

    List() {
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        len=0;
    }

    void addNode(Node*newNode){
        Node*headNext=head->next;
        newNode->next=headNext;
        newNode->prev=head;
        head->next=newNode;
        headNext->prev=newNode;
        len++;
    }

    void deleteNode(Node*delNode){
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        len--;
    }
};


class LFUCache {
private:
    unordered_map<int,List*>freqListMap;
    unordered_map<int,Node*>addrOfKey;
    int minFreq,currSize;
    int cacheCapacity;

    void updateFreqListMap(Node*node){
        addrOfKey.erase(node->key);
        freqListMap[node->count]->deleteNode(node);
        if(node->count == minFreq && freqListMap[node->count]->len==0){
            minFreq++;
        }

        List* nextHigherFreqList;
        if(freqListMap.find(node->count+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->count+1];
        }else{
            nextHigherFreqList=new List();
        }
        node->count+=1;
        nextHigherFreqList->addNode(node);
        freqListMap[node->count]=nextHigherFreqList;
        addrOfKey[node->key]=node;
    }

public:
    LFUCache(int capacity) {
        cacheCapacity=capacity;
        minFreq=0;
        currSize=0;
    }
    
    int get(int key) {
        if(addrOfKey.find(key)==addrOfKey.end()){
            return -1;
        }
        Node*resNode= addrOfKey[key];
        int res = resNode->val;
        updateFreqListMap(resNode);
        return res;
    }
    
    void put(int key, int value) {
        if(addrOfKey.find(key)!=addrOfKey.end()){
            Node*existingNode= addrOfKey[key];
            existingNode->val=value;
            updateFreqListMap(existingNode);
        }else{
            if(currSize==cacheCapacity){
                List * list= freqListMap[minFreq];
                Node*lastNode= list->tail->prev;
                int keyToBeErased= lastNode->key;
                addrOfKey.erase(keyToBeErased);
                freqListMap[minFreq]->deleteNode(lastNode);
                currSize--;
            }

            currSize++;
            minFreq=1;
            List* listFreq= new List();
            if(freqListMap.find(minFreq)!= freqListMap.end()){
                listFreq= freqListMap[minFreq];
            }
            Node*  newNode= new Node(key,value);
            listFreq->addNode(newNode);
            addrOfKey[key]=newNode;
            freqListMap[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */