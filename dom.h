#pragma once
#include <memory>
#include <sstream>

using namespace std;

class DomTag {
public:
    DomTag() : m_opening(false), m_value("") {}
    ~DomTag() {}

    friend istream & operator >> (std::istream &is, DomTag &rhs);

    bool is_opening() { return m_opening; }
    const string& value() { return m_value; }
private:
    bool m_opening;
    string m_value;
};

class DomNode {
public:
    DomNode() : m_value("") {}
    DomNode(const string& value) : m_value(value) {}
    ~DomNode() {}

    const string& value() const { return m_value; }
private:
    string m_value;
};

class DomTree {
public:
    DomTree() : m_root(nullptr) {}
    ~DomTree() {}

    shared_ptr<const DomNode> root() { return m_root; }
    friend istream & operator >> (std::istream &is, DomTree &rhs);
private:
    shared_ptr<DomNode> m_root;
}; 
