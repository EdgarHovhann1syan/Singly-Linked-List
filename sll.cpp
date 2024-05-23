#include "sll.h"
#include <iostream>
//Constructors 
SLL::SLL() : m_head{nullptr} {}
SLL::SLL(Node *head) : m_head{head} {}
SLL::Node::Node() : m_next{nullptr}, m_data{0} {}
SLL::Node::Node(int data, Node* next) : m_next{next}, m_data{data} {}

//Member Functions
void SLL::push_front(int data)
{
    Node* newNode = new Node(data, m_head);
    m_head = newNode;
}
void SLL::pop_front()
{
    Node* deletedNode = m_head;
    m_head = m_head->m_next;
    delete deletedNode;
}
void SLL::insert(int pos, int value)
{
    if(pos == 0)
    {
        this->push_front(value);
    }
    Node* current = m_head;
    for(int i = 0; i < pos - 1; ++i)
    {
        if(!current)
        {
            throw std::out_of_range("Invlaid Position");
            return;
        }
        current = current->m_next;
    }
    if(!current)
    {
        throw std::out_of_range("Invlaid Position");
        return;
    }
    Node* newNode = new Node(value, current->m_next);
    current->m_next = newNode;

}
void SLL::insert(int pos, int count, int val)
{
    if(pos == 0)
    {
        for(int i = 0; i < count; ++i)
        {
            this->push_front(val);
        }
        return;
    }
    Node* current = m_head;
    for(int i = 0; i < pos - 1; ++i)
    {
        if(!current)
        {
            throw std::out_of_range("Invlaid Position");
            return;
        }
        current = current->m_next;
    }
    if(!current)
    {
        throw std::out_of_range("Invlaid Position");
        return;
    }
    for(int i = 0; i < count; ++i)
    {
        Node* newNode = new Node(val, current->m_next);
        current->m_next = newNode;
        current = current->m_next;
    }

}
void SLL::remove(int pos)
{
    if(pos == 0)
    {
        this->pop_front();
        return;
    }
    Node* current = m_head;
    for(int i = 0; i < pos - 1; ++i)
    {
        if(!current)
        {
            throw std::out_of_range("Invlaid Position");
            return;
        }
        current = current->m_next;
    }
    if(!current)
    {
        throw std::out_of_range("Invlaid Position");
        return;
    }
    Node* deletedNode = current->m_next;
    current->m_next = current->m_next->m_next;
    delete deletedNode;
}
void SLL::print() const
{
    Node* current = m_head;
    while (current)
    {
        std::cout << current->m_data << "  ";
        current = current->m_next;
    }
    
}
// //Destructor
// SLL::~SLL()
// {
//     while(m_head)
//     {
//         Node* deleteNode = m_head;
//         delete deleteNode;
//         m_head = m_head->m_next;
//     }
// }


