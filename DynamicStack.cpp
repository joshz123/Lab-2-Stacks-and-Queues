#include "DynamicStack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    capacity_ = 16;
    size_=0;
    init_capacity_ =16;
    capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    items_ = new StackItem[capacity];
    size_ = 0;
    init_capacity_ = capacity;
    capacity_ = capacity;

}

DynamicStack::~DynamicStack()
{
    delete[] items_;
}

bool DynamicStack::empty() const
{
    return size_==0;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if(capacity_-size_>=1){
        //todo Should pointers or arrays be used. should i just move all items in the stack?
    }

}

StackItem DynamicStack::pop()
{
}

StackItem DynamicStack::peek() const
{
}

void DynamicStack::print() const
{
}
