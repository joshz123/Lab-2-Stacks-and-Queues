#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;
// Works on FILO principle
CircularQueue::CircularQueue()
{
    items_ = new QueueItem[capacity_];
    head_ = tail_ = -1; //todo check if head and tail should be 0 or -1 in an empty queue
    capacity_=16;
    size_=0;



}
//todo remember to use deletes
CircularQueue::CircularQueue(unsigned int capacity)
{
    items_ = new QueueItem[capacity_];
    head_ = tail_ = -1;
    capacity_=16;
    size_=0;
}

CircularQueue::~CircularQueue()
{
    delete [] items_;
}

bool CircularQueue::empty() const
{
    return size_ == 0;
}

bool CircularQueue::full() const
{
    return size_==capacity_;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if(size_==capacity_) //todo check if i need a condition for front%size==rear for full
        return false;

    else if (size_==0){
        head_ = 0;
        tail_ = 1;
        items_[head_] = value;
        size_++;
        return true;

    }
    else if (head_!=0 && tail_==size_){
        tail_ = 0;
        items_[tail_]=value;
        tail_++;
        size_++;
        return true;
    }
    else{
        items_[tail_]=value;
        tail_++;
        size_++;
        return true;
    }



}

QueueItem CircularQueue::dequeue() //todo check what happens in case head == tail-1 do they both get reset? you dont want head to pass tail
{
    if(size_==0)
        return EMPTY_QUEUE;

    if(head_==size_-1){
        int temp = items_[head_];
        items_[head_] = -1;
        head_ =0;
        size_--;
        return temp;
    }
    else if(size_==1){
        int temp = items_[head_];
        size_--;
        head_++;
        return temp;
    }
    else {
        int temp = items_[head_];
        items_[head_]==0; //todo check if this is even necessary
        head_++;
        size_--;
        return temp;
    }
}

QueueItem CircularQueue::peek() const
{
    return size_ != 0 ? items_[head_] : EMPTY_QUEUE;
}

void CircularQueue::print() const
{
}
