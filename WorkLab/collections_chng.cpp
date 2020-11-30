#include <collections_chng.h>
#include <operations.h>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

void collections_chng::eliminate(size_t position_, size_t length_) {
    if ((position_ + length_ <= m_text.size()) && (length_ != 0)) // checker for delete operation
    redo_stack.clear(), apply_operation(make_shared<eliminate_>(m_text.substr(position_, length_), position_)); // smart pointer for creation shared_ptr
}

void collections_chng::paste(const string &text_, size_t position_) {
    if ((position_ <= m_text.size()) && !text_.empty()) // checker for insert operation
    redo_stack.clear(), apply_operation(make_shared<paste_>(text_, position_)); // smart pointer for creation shared_ptr
}

void collections_chng::supersede(const string &new_, size_t position_, size_t length_) {
    if ((position_ + length_ <= m_text.size()) && !new_.empty()) // checker for replace operation
    redo_stack.clear(), apply_operation(make_shared<supersede_>(m_text.substr(position_, length_), new_, position_)); // smart pointer for creation shared_ptr
}

void collections_chng::undo() {
    if (!undo_stack.empty()) { // checker for filling of undo stack
        auto operation = undo_stack.top();
        undo_stack.pop(), operation->undo(m_text),redo_stack.push(move(operation));
}}

void collections_chng::redo() {
    if (!redo_stack.empty()) { // checker for filling of undo stack
        auto operation = redo_stack.top();
        redo_stack.pop(),operation->apply(m_text),undo_stack.push(move(operation));
}}

const string &collections_chng::text() const {
    return m_text;
}

void collections_chng::apply_operation(shared_ptr<virtual_txt_operations>&& operation_) {
    operation_->apply(m_text),undo_stack.push(move(operation_));
}
