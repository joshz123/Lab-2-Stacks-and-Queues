#include "DynamicStack.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;
typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    capacity_ = 16;
    size_ = 0;
    init_capacity_ = 16;
    items_ = new StackItem[capacity_];
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
    return size_ == 0;
}

int DynamicStack::size() const {
    return size_;
}

void DynamicStack::push(StackItem value) {
    if (size_ == capacity_) {
        capacity_ *= 2;
        //todo Should pointers or arrays be used. should i just move all items in the stack?
        StackItem *temp = new StackItem[capacity_]; //todo cehck if these are round or square brackets
        for (int i = 0; i < size_; i++)
            temp[i] = items_[i];

        items_ = temp;
        items_[size_] = value;
        size_++;


    } else {
        items_[size_] = value;
        size_++;
    }


}

StackItem DynamicStack::pop() {
    if (size_ == 0)
        return EMPTY_STACK;
    else {
        StackItem popped = items_[size_-1];

        if (size_ <= capacity_ / 4&&capacity_/4>init_capacity_) {
            capacity_ /= 2;
            auto *temp = new StackItem[capacity_];
            items_ = temp;
        }
        size_--;//todo should this be here
        return popped;

    }


}

StackItem DynamicStack::peek() const {
    if (size_ == 0)
        return EMPTY_STACK;
    else
        return items_[size_ - 1];

}

void DynamicStack::print() const {
    for (int i = 0; i < size_; i++)
        cout << items_[i] << "\t";
}
