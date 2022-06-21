// struct Node{
//     int cnt,key,value;
//     Node* next;
//     Node* prev;
//     Node(int _key,int _value){
//         key=_key;
//         value=_value;
//         cnt=1;
//     }
// };
// struct List{
//     int size;
//     Node* head;
//     Node* tail;
//     List(){
//         head=new Node(-1,-1);
//         tail=new Node(-1,-1);
//         head->next=tail;
//         tail->prev=head;
//         size=0;
//     }
//     void addNode(Node *newNode){
//         Node* temp=head->next;
//         newNode->next=temp;
//         newNode->prev=newNode;
//         head->next=newNode;
//         temp->prev=newNode;
//         size++;
//     }
//     void deleteNode(Node* delNode){
//         Node* delPrev=delNode->prev;
//         Node* delNext=delNode->next;
//         delPrev->next=delNext;
//         delNext->prev=delPrev;
//         size--;
//     }
// };

// class LFUCache {
// public:
    
//     LFUCache(int capacity) {
        
//     }
    
//     int get(int key) {
        
//     }
    
//     void put(int key, int value) {
        
//     }
// };

// /**
//  * Your LFUCache object will be instantiated and called as such:
//  * LFUCache* obj = new LFUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */

struct node{
    public:
        int key,value,cnt;
        node* next;
        node* prev;
        node(int _key,int _value){
            key=_key;
            value=_value;
            cnt=1;
        }
    };
    struct List {
        int size;
        node* head;
        node* tail;
        
        List(){
            head = new node(0, 0); 
            tail = new node(0,0); 
            head->next = tail;
            tail->prev = head; 
            size = 0;
        }
        
        void addNode(node* newNode){
            node* temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
            size++;
        }

        void delNode(node* delnode){
            node* delprev = delnode->prev; 
            node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
            }
        
    };
class LFUCache {
public:
    map<int,node*>keyNode;
    map<int,List*>freqm;
    
    int minFreq=0,currSize=0,cap;
    LFUCache(int capacity) {
       cap=capacity;
    }

//okay function
    void updateNode(node *node) {
        keyNode.erase(node->key); 
        freqm[node->cnt]->delNode(node); 
        if(node->cnt == minFreq && freqm[node->cnt]->size == 0) {
            minFreq++;      //min freq badha rahe hai
        }
        
        List* nextHigherFreqList = new List();
        if(freqm.find(node->cnt + 1) != freqm.end()) {
            nextHigherFreqList = freqm[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addNode(node); 
        freqm[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    //khtm
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            node* temp = keyNode[key];
            int res=temp->value;
            updateNode(temp);
            return res;
        }
        return -1;                                 
    }
    
    void put(int key, int value) {  
        if(cap==0) return;
        //min frequency        
        if(keyNode.find(key)!=keyNode.end()){
            node* temp = keyNode[key];
            temp->value=value;
            updateNode(temp);
        }
        else{
            if(currSize == cap){
                List* temp = freqm[minFreq];
                keyNode.erase(temp->tail->prev->key);
                freqm[minFreq]->delNode(temp->tail->prev);
                currSize--; 
            }
            currSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            
            if(freqm.find(minFreq) != freqm.end()) {
                listFreq = freqm[minFreq]; 
            }
            node* nodee = new node(key, value); 
            listFreq->addNode(nodee);
            keyNode[key] = nodee; 
            freqm[minFreq] = listFreq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */