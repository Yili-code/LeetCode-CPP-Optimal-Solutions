#include <iostream>
#include <memory>

using namespace std;

class Node {
public:
  int value;
  shared_ptr<Node> next;
  weak_ptr<Node> prev;

  Node(int val, shared_ptr<Node> prevNode, shared_ptr<Node> nextNode)
      : value(val), next(nextNode), prev(prevNode) {}
};

class MyLinkedList {
private:
  shared_ptr<Node> head;
  shared_ptr<Node> tail;
  int listSize;

public:
  MyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

  int get(int index) {
    if (index < 0 || index >= listSize)
      return -1;
    auto curr = head;
    for (int i = 0; i < index; ++i)
      curr = curr->next;
    return curr->value;
  }

  void addAtHead(int val) {
    auto newNode = make_shared<Node>(val, nullptr, head);
    if (head) {
      head->prev = newNode;
    } else {
      tail = newNode;
    }
    head = newNode;
    listSize++;
  }

  void addAtTail(int val) {
    auto newNode = make_shared<Node>(val, tail, nullptr);
    if (tail) {
      tail->next = newNode;
    } else {
      head = newNode;
    }
    tail = newNode;
    listSize++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > listSize)
      return;

    if (index == 0) {
      addAtHead(val);
    } else if (index == listSize) {
      addAtTail(val);
    } else {
      auto curr = head;
      for (int i = 0; i < index; ++i)
        curr = curr->next;

      auto prevNode = curr->prev.lock();
      auto newNode = make_shared<Node>(val, prevNode, curr);

      if (prevNode)
        prevNode->next = newNode;
      curr->prev = newNode;

      listSize++;
    }
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= listSize)
      return;

    if (index == 0) {
      head = head->next;
      if (head)
        head->prev.reset();
      else
        tail = nullptr;
    } else if (index == listSize - 1) {
      tail = tail->prev.lock();
      if (tail)
        tail->next = nullptr;
      else
        head = nullptr;
    } else {
      auto curr = head;
      for (int i = 0; i < index; ++i)
        curr = curr->next;

      auto prevNode = curr->prev.lock();
      auto nextNode = curr->next;

      if (prevNode)
        prevNode->next = nextNode;
      if (nextNode)
        nextNode->prev = prevNode;
    }

    listSize--;
  }
};
