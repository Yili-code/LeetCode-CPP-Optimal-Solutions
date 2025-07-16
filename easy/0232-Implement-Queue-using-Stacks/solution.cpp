class MyQueue {
private:
  stack<int> inStack;
  stack<int> outStack;

  void transfer() {
    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

public:
  MyQueue() {}

  void push(int x) { inStack.push(x); }

  int pop() {
    if (!inStack.empty()) {
      transfer();
    }

    int val = outStack.top();
    outStack.pop();
    return val;
  }

  int peek() {
    if (!inStack.empty()) {
      transfer();
    }

    int val = outStack.top();
    return val;
  }

  bool empty() {
    if (!inStack.empty()) {
      transfer();
    }

    return outStack.empty() ? true : false;
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
In   out   out   in
4     1     2     5
3     2     3
2     3     4
1     4

2 3 4 5
*/