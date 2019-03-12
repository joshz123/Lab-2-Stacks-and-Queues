#ifndef LAB2_TESTS_HPP
#define LAB2_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include <iostream>
#include "DynamicStack.hpp"
#include "CircularQueue.hpp"
using namespace std;
class DynamicStackTest {
public:
    bool test1() {
        unsigned int size = 24;

        DynamicStack default_size_stack;
        ASSERT_TRUE(default_size_stack.empty() == true)
        ASSERT_TRUE(default_size_stack.size() == 0)

        DynamicStack stack(size);
        ASSERT_TRUE(stack.empty() == true)
        ASSERT_TRUE(stack.size() == 0)
        return true;
    }

    bool test2() {
        DynamicStack stack;
        stack.push(10);
        ASSERT_TRUE(stack.empty() == false)
        ASSERT_TRUE(stack.size() == 1)
        ASSERT_TRUE(stack.pop() == 10);
        ASSERT_TRUE(stack.empty() == true)
        ASSERT_TRUE(stack.size() == 0)
        return true;
    }

    bool test3() {
        DynamicStack stack(24);
        stack.push(10);
        stack.push(20);
        ASSERT_TRUE(stack.peek() == 20)
        ASSERT_TRUE(stack.pop() == 20)
        ASSERT_TRUE(stack.pop() == 10)
        ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
        ASSERT_TRUE(stack.peek() == DynamicStack::EMPTY_STACK)
        return true;
    }

    bool test4() {
        DynamicStack stack;
        ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
        return true;
    }

    bool test5() {
        DynamicStack stack(24);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        ASSERT_TRUE(stack.pop() == 30)
        ASSERT_TRUE(stack.pop() == 20)
        ASSERT_TRUE(stack.pop() == 10)
        return true;
    }

    bool test6() {
        DynamicStack stack(24);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.print();
        ASSERT_TRUE(stack.pop() == 30)
        ASSERT_TRUE(stack.pop() == 20)
        ASSERT_TRUE(stack.pop() == 10)
        ASSERT_TRUE(stack.pop() == DynamicStack::EMPTY_STACK)
        return true;

    }


};

class CircularQueueTest {
public:
    bool test1() {
        CircularQueue queue;
        ASSERT_TRUE(queue.empty() == true)
        ASSERT_TRUE(queue.full() == false)
        ASSERT_TRUE(queue.size() == 0)
        ASSERT_TRUE(queue.size_ == 0)
        ASSERT_TRUE(queue.capacity_ == 16)
        return true;
    }

    bool test2() {
        CircularQueue queue;
        ASSERT_TRUE(queue.enqueue(10) == true)
        ASSERT_TRUE(queue.empty() == false)
        ASSERT_TRUE(queue.full() == false)
        ASSERT_TRUE(queue.size_ == 1)
        ASSERT_TRUE(queue.head_ == 0)
        ASSERT_TRUE((queue.tail_ == 0) || (queue.tail_ == 1))
        ASSERT_TRUE(queue.dequeue() == 10);
        ASSERT_TRUE(queue.empty() == true)
        ASSERT_TRUE(queue.size_ == 0)
        return true;
    }

    bool test3() {
        CircularQueue queue;
        ASSERT_TRUE(queue.enqueue(10) == true)
        ASSERT_TRUE(queue.enqueue(20) == true)
        ASSERT_TRUE(queue.empty() == false)
        ASSERT_TRUE(queue.full() == false)
        ASSERT_TRUE(queue.size_ == 2)
        ASSERT_TRUE(queue.head_ == 0)
        ASSERT_TRUE((queue.tail_ == 1) || ((queue.tail_ ==
                                            2))) //todo check that this has been handled
        ASSERT_TRUE(queue.peek() == 10);
        ASSERT_TRUE(queue.dequeue() == 10);
        ASSERT_TRUE(queue.peek() == 20);
        ASSERT_TRUE(queue.dequeue() == 20);
        ASSERT_TRUE(queue.peek() == CircularQueue::EMPTY_QUEUE);
        ASSERT_TRUE(queue.dequeue() == CircularQueue::EMPTY_QUEUE);
        ASSERT_TRUE(queue.empty() == true)
        ASSERT_TRUE(queue.size_ == 0)
        ASSERT_TRUE(queue.head_ == 2)
        ASSERT_TRUE((queue.tail_ == 1) || (queue.tail_ == 2))
        return true;
    }

    bool test4() {
        CircularQueue queue;
        for (int ind = 0; ind <= queue.capacity_; ind++) {
            queue.enqueue(ind);
        }
        ASSERT_TRUE(queue.peek() == 0)
        //queue.print(); // double check that this shows 0 ->15
        ASSERT_TRUE(queue.enqueue(5) == false)
        ASSERT_TRUE(queue.dequeue() == 0)
        ASSERT_TRUE(queue.peek() == 1)
        ASSERT_TRUE(queue.enqueue(16) == true)
        //  queue.print(); //double check that this shows 1 -> 16
        ASSERT_TRUE(queue.enqueue(17) == false)
        ASSERT_TRUE(queue.dequeue() == 1)
        ASSERT_TRUE(queue.enqueue(17) == true)
        for (int ind = 2; ind < queue.capacity_ + 2; ind++) {
            ASSERT_TRUE(queue.dequeue() == ind)

        }

        return true;


    }

    bool test5() {
        CircularQueue QEY;
        for (int i = 0; i < 16; i++) {
            ASSERT_TRUE(QEY.enqueue(i))
            ASSERT_TRUE(QEY.size_ = i +1)

        }

        QEY.print();
        ASSERT_TRUE(QEY.full())
        ASSERT_FALSE(QEY.enqueue(3))

        for (int i = 0; i < 16; i++) {
            ASSERT_TRUE(QEY.peek()==i)
            ASSERT_TRUE(QEY.dequeue() == i);
            ASSERT_TRUE(QEY.size() == QEY.size_)
            //cout<<"size: "<<QEY.size_<<" index: "<<15-i<<endl;
            ASSERT_TRUE(QEY.size_ == 15-i)


        }


        ASSERT_TRUE(QEY.peek() == CircularQueue::EMPTY_QUEUE)
        ASSERT_TRUE(QEY.dequeue() == CircularQueue::EMPTY_QUEUE)
        ASSERT_TRUE(QEY.size_ == 0)
        ASSERT_TRUE(QEY.empty())


        DynamicStack A;



        return true;
    }

};


#endif