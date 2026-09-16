class Node{
    int data ;
    int min;
    Node next;
    Node(int data,int min,Node next){
        this.data=data;
        this.min=min;
        this.next=next;
    }
}

class MinStack {
    private Node head;
    public MinStack() {
        Node head=null;
    }
    
    public void push(int value) {
        if(head==null){
            head=new Node(value,value,null);
        }
        else{
            Node temp=new Node(value,Math.min(value,head.min),head);
            head=temp;
        }
    }
    
    public void pop() {
        head=head.next;
    }
    
    public int top() {
        return head.data;
    }
    
    public int getMin() {
        return head.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */