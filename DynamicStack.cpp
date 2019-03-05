#include "DynamicStack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    capacity_ = 16;
    size_=0;
    init_capacity_ =16;
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
    if(size_==0)
        return true;
    return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
   if(size_==capacity_)
   {
       capacity_*=2;
       StackItem* temp= new StackItem(capacity_);
       for(int i=0; i<size; i++)
           temp[i]=items_[i];
       delete[] items_;
       temp=items_;
       temp=NULL;
       items_[size_]=value;
       size_++;
       
   }
    else
    {
        items_[size_]=value;
        size_++;
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
