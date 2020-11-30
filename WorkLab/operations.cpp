#include <operations.h>
#include <string>

using namespace std;

//PASTE

void paste_::apply(string &text_) const { //apply of pasting
    text_.insert(m_position, m_text);
}

void paste_::undo(string &text_) const { //undo of pasting
    text_.erase(m_position, m_text.size());
}

//ELIMINATE

void eliminate_::apply(string &text_) const { //apply of eliminating
    text_.erase(m_position, m_text.size());
}

void eliminate_::undo(string &text_) const { //undo of eliminating
    text_.insert(m_position, m_text);
}

//SUPERSEDE

supersede_::supersede_(const string& old_, const string& new_, size_t position_) : m_remove(old_, position_), m_insert(new_, position_) { }

void supersede_::apply(string &text_) const { //apply of superseding
    m_remove.apply(text_),m_insert.apply(text_);
}

void supersede_::undo(string &text_) const { //undo of superseding
    m_insert.undo(text_),m_remove.undo(text_);
}
