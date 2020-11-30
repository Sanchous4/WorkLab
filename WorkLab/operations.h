#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <txt_operations.h>
#include <string>

using namespace std;

class paste_ : public txt_operations {
public:
    paste_(const string& text_, size_t position_) : txt_operations(text_, position_) { }
    void apply(string& text_) const override;
    void undo(string& text_) const override;
};

class eliminate_ : public txt_operations {
public:
    eliminate_(const string& text_, size_t position_) : txt_operations(text_, position_) { }
    void apply(string& text_) const override;
    void undo(string& text_) const override;
};

class supersede_ : public virtual_txt_operations {
private:
    eliminate_ m_remove;
    paste_ m_insert;
public:
    supersede_(const string& old_, const string& new_, size_t position_);
    void apply(string& text_) const override;
    void undo(string& text_) const override;
};

#endif // OPERATIONS_H
