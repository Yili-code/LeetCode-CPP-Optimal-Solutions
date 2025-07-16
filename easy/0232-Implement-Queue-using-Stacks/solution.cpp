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