#ifndef StACK_H
#define StACK_H

#include <memory>
#include <istream>
#include <ostream>

using namespace std;

template<typename t>
class stack {
private:
    class stack_obj {
    private:
        t obj_val;
        unique_ptr<stack_obj> obj_next{nullptr};
    public:
        stack_obj() = delete;
        stack_obj(const t& value_, unique_ptr<stack_obj>&& next_) : obj_val{value_}, obj_next{move(next_)} { } // smart pointer for move obj
        stack_obj(t&& value_, unique_ptr<stack_obj>&& next_) : obj_val{move(value_)}, obj_next{move(next_)} { } // smart pointer for move obj
        t& value() { return obj_val; }
        unique_ptr<stack_obj>& next() { return obj_next; }
    };

    unique_ptr<stack_obj> head{nullptr};
    size_t stk_size{0};
public:
    // constructors
    stack() = default;
    stack(const stack& other_);
    stack(stack&& other_) = default;
    ~stack() = default;

    // operator = overloading
    stack& operator=(const stack& other_);
    stack& operator=(stack&& other_) = default;
    t& top();

    // functions of stack
    void pop();
    void push(const t& value_);
    void push(t&& value_);
    size_t size() const;
    bool empty() const;
    void clear();
};

template<typename t> stack<t>& stack<t>::operator=(const stack& other_) {
    if (&other_ != this) {
        clear();
        add_obj(other_);
    }
    return *this;
}

template<typename t> t& stack<t>::top() {
    if (head == nullptr) {
        throw out_of_range("top() of empty stack");
    }
    return head->value();
}

template<typename t> void stack<t>::pop() {
    if (head != nullptr)
        head = move(head->next()),--stk_size;
}

template<typename t> void stack<t>::push(const t& value_) {
    head = make_unique<stack_obj>(value_, move(head)),++stk_size;
}

template<typename t> void stack<t>::push(t&& value_) {
    head = make_unique<stack_obj>(move(value_), move(head)),++stk_size;
}

template<typename t> size_t stack<t>::size() const { return stk_size; }

template<typename t> bool stack<t>::empty() const { return head == nullptr; }

template<typename t> void stack<t>::clear() { head = nullptr,stk_size = 0; }

#endif // StACK_H
