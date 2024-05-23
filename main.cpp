#include <iostream>
#include "sll.h"
int main() {
    SLL s(nullptr);
    s.push_front(1);
    s.push_front(4);
    s.push_front(3);
    s.insert(0, 5, 21);
    s.remove(6);
    s.print();
    return 0;
}
