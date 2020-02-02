class Node{
public:
    int val;
    int k;
    Node* next;
    Node* prev;
};
class LRUCache {
public:
    map<int,Node*> m;
    int cap;
    Node* head = new Node();
    Node* tail = new Node();
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* n = m[key];
        remove(n);
        m.erase(n->k);
        add(n->k,n->val);
        return n->val;
    }
    
    void put(int key, int value) {
        if(m.size()<cap){
            if(m.find(key) == m.end()){
                add(key,value);
            }
            else {
                remove(m[key]);
                m.erase(key);
                add(key,value);
            }
        }
        else if(m.size()==cap && m.find(key) != m.end()){
            remove(m[key]);
            m.erase(key);
            add(key,value);
        }
        else{
            Node* n = tail->prev;
            remove(n);
            m.erase(n->k);
            add(key,value);
        }
    }
    void add(int key, int value){
        Node* newn = new Node();
        newn->k = key;
        newn->val = value;
        Node* nextn = head->next;
        newn->next = nextn;
        newn->prev = head;
        nextn->prev = newn;
        head->next = newn;
        m[key] = newn;
    }
    void remove(Node* node){
        Node* nextn = node->next;
        Node* prevn = node->prev;
        prevn->next = nextn;
        nextn->prev = prevn;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */