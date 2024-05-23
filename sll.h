#ifndef SLL_SLL_H
#define SLL_SLL_H

class SLL
{
public:
    void insert(int pos, int val);
    void insert(int pos, int count, int val);
    void remove(int pos);
    void push_front(int val);
    void pop_front();
    void print() const;

private:
    struct Node
    {
        Node* m_next;
        int m_data;
        Node();
        Node(int data, Node* next = nullptr);
    };

public:
    SLL();
    SLL(Node* head = nullptr);
    // ~SLL();

private:
    Node* m_head;
};

#endif // SLL_SLL_H
