#ifndef __SRC_STACK_ADT_CC__
#define __SRC_STACK_ADT_CC__

#include <memory>

#include "../include/stack_adt.h"
#include "../include/stack_exception.h"

using namespace summer_projects;

template <typename T>
stack<T>::stack() : _size(0) {  };

template <typename T>
stack<T>::~stack() {
    this->top.reset();
}

template <typename T>
void stack<T>::push(const T& item) {
    std::unique_ptr<Frame> new_frame = std::make_unique<Frame>(item);

    new_frame->next = std::move(this->top);
    this->top = std::move(new_frame);

    ++this->_size;
}

// pop the top most item
template <typename T>
T stack<T>::pop(void) {
    if (this->empty())
        throw StackEmptyException();

    T top_ = this->top->item;

    this->top = std::move(this->top->next);

    --this->_size;
    return top_;
}

template <typename T>
const T* stack<T>::peek(void) const {
    if (this->empty())
        throw StackEmptyException();
    return &(this->top.item);
}

template <typename T>
unsigned stack<T>::size(void) const {
    return this->_size;
}

#endif // __src_stack_adt.cc
