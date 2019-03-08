#include "DynamicStack.hpp"
#include <iostream>

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;
using namespace std;

DynamicStack::DynamicStack() {
    capacity_ = 16;
    size_ = 0;
    init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity) {
    items_ = new StackItem[capacity];
    size_ = 0;
    init_capacity_ = capacity;
    capacity_ = capacity;

}

DynamicStack::~DynamicStack() {
    delete[] items_;
}

bool DynamicStack::empty() const {
    if (size_ == 0)
        return true;
    return false;
}

int DynamicStack::size() const {
    return size_;
}

void DynamicStack::push(StackItem value) {
    if (size_ == capacity_) {
        capacity_ *= 2;
        StackItem *temp = new StackItem(capacity_);
        for (int i = 0; i < size_; i++)
            temp[i] = items_[i];
        delete[] items_;
        temp = items_;
        temp = NULL;
        items_[size_] = value;
        size_++;

    } else {
        items_[size_] = value; //todo this line of code is making the program crash. check it out. it prevent output. its possible because the index size_ is outside the array
        size_++;
    }


}

StackItem DynamicStack::pop() {
    if (size_ == 0)
        return EMPTY_STACK;

    StackItem temp1 = items_[size_];
    StackItem *temp2 = new StackItem(size_);
    for (int i = 0; i < size_ - 1; i++)
        temp2[i] = items_[i];
    delete[] items_;
    temp2 = items_;
    temp2 = nullptr;
    if (size_ < capacity_ / 4)
        capacity_ /= 2;
    return temp1;

}

StackItem DynamicStack::peek() const {

    if (size_ == 0)
        return EMPTY_STACK;

    return items_[size_];
}

void DynamicStack::print() const {
    for (int i = 0; i < size_; i++)
        cout << items_[i] << "\t";
}
