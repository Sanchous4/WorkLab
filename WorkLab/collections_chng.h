#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <stack.h>
#include <txt_operations.h>
#include <memory>

using namespace std;

class collections_chng {
private:
    string m_text;

    stack<shared_ptr<virtual_txt_operations>> undo_stack; // smart pointer of class obj
    stack<shared_ptr<virtual_txt_operations>> redo_stack; // smart pointer of class obj

    void apply_operation(shared_ptr<virtual_txt_operations>&& operation_); //
public:
    collections_chng() = default;
    void eliminate(size_t position_, size_t length_);
    void paste(const string& text_, size_t position_);
    void supersede(const string& new_, size_t position_, size_t length_);

    void undo();
    void redo();

    const string& text() const;
};

#endif // TEXTEDITOR_H
