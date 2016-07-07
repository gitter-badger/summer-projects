#ifndef __INCLDUE_STACK_EXCEPTION_H__
#define __INCLDUE_STACK_EXCEPTION_H__

#include <exception>
#include <string>

class StackException : public std::exception {
    public:
        StackException(const std::string& err_msg) :
            err_msg(err_msg) {}

        virtual const char* what() {
            return this->err_msg.c_str();
        }

    private:
        std::string err_msg;
};

class StackEmptyException : public StackException {
    public:
        StackEmptyException() : StackException("Stack is empty!") {}
};

#endif // __INCLUDE_STACK_EXCEPTION_H__

