class myQueue {

  public:
    stack<int> st1;
    stack<int> st2;
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        
    }

    void dequeue() {
        // Implement dequeue operation
        if(!st1.empty()) st1.pop();
    }

    int front() {
        // Implement front operation
        return !st1.empty()?st1.top():-1;
    }

    int size() {
        // Implement size operation
        return st1.size();
    }
};
