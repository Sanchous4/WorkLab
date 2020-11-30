#ifndef TEXTOPERATION_H
#define TEXTOPERATION_H

#include<string>

using namespace std;

class virtual_txt_operations {
public:
    virtual void apply(string& text_) const = 0;
    virtual void undo(string& text_) const = 0;
    virtual ~virtual_txt_operations() = default;
};

class txt_operations : public virtual_txt_operations {
public:
    txt_operations(const std::string &text_, size_t position_) : m_text{text_}, m_position{position_} { }
protected:
    std::string m_text;
    size_t m_position{0};
};

#endif // TEXTOPERATION_H
