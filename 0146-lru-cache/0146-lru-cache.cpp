class node{
    public:
        int data;
        node *next;
        node(int value){
            next=NULL;
            this->data=value;
        }
};

class LRUCache {
public:
    int capacity,size;
    unordered_map<int,node*>m;
    node *head;
    
    LRUCache(int capacity) {
    this->capacity=capacity;
    head=NULL;
    size=0;    
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        node*ans=m[key];
        if(ans==head){
            return ans->data;
        }
      
      node*curr=head;
      while(curr->next!=ans){
        curr=curr->next;
      }  
      curr->next=curr->next->next;
      ans->next=head;
      head=ans;
      return ans->data;
    }
    
    void put(int key, int value) {
        if (capacity==0){
            return;
        }
        if(m.find(key)!=m.end()){
            node *ans=m[key];
            ans->data=value;
            get(key);
            return;
            
        }
        node *curr=new node(value);
        m[key]=curr;
        curr->next=head;
        head=curr;
        size++;
        if(capacity<size){
            curr=head;
            while(curr->next->next){
                curr=curr->next;
            }
            node *temp=curr->next;

            for(auto it=m.begin();it!=m.end();it++){
                if(it->second == temp){
                    m.erase(it);
                    break;
                }
            }

            delete temp;
            curr->next=NULL;
            size--;
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */