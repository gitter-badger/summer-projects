#ifndef __INCLUDE_STACK_ADT_H__
#define __INCLUDE_STACK_ADT_H__

#include <memory>

namespace summer_projects {

    /**
     * @class   stack
     * @brief   Stack template implementation.
     *
     * Stack implementation using singly linked lists.
     * Supprots any kind of data, can preform the
     * following operations:
     * + *Push*: push item into stack.
     * + *Pop*: pop last element from stack.
     * + *Peek*: take a look at the last element.
     * + *Size*: number of elements on stack.
     */
    template <typename T>
    class stack {
        private:

            /**
             * @struct Frame
             * @brief Frame implementation using struct.
             */
            typedef struct Frame{
                T item;                         ///< item container
                std::unique_ptr<Frame> next;    ///< next frame.
                Frame(T item) : item(item) {};  ///< Frame contructor
            } Frame;

            unsigned _size;                     ///< Stack size.
            std::unique_ptr<Frame> top;         ///< Stack top most item.

        public:

            /**
             * @fn stack()
             * @brief Stack contructor
             */
            stack();

            /**
             * @fn ~stack()
             * @brief Stack destructor
             */
            ~stack();

            /**
             * @fn inline bool empty(void) const
             * @brief Check if stack is empty.
             *
             * Returns True stack is empty, false
             * otherways.
             *
             * @return Boolean value, true if empty
             */
            inline bool empty(void) const {
                return this->top.get() == nullptr;
            }

            /**
             * @fn void push(const T&)
             * @brief Push item into stack.
             *
             * Template member function pushes item
             * of type T into stack.
             *
             * @param item Type T item.
             * @return Nothing.
             */
            void push(const T&);

            /**
             * @fn T pop(void)
             * @brief Pop the top most element from stack.
             *
             * Template member function, pops the top most
             * element from stack, throw StackEmptyException
             * exception if stack is empty.
             *
             * @exception StackEmptyException
             * @see StackEmptyException
             * @return Value held by last Frame on stack.
             */
            T pop(void);

            /**
             * @fn const T* peek(void) const
             * @brief Returns a pointer to the value held
             * by the top most Frame on Stack
             *
             * @return Type T pointer to the value held by the
             * top most Frame on Stack
             */
            const T* peek(void) const;

            /**
             * @fn unsigned size(void) const
             * @brief Returns the size of Stack
             * @return Size of stack.
             * */
            unsigned size(void) const;
    };
};

#include "../src/stack_adt.cc"

#endif //__INCLUDE_STACK_ADT_H__
