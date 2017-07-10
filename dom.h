#pragma once
#include <memory>
#include <sstream>

using namespace std;

class DomNode {
public:
    DomNode();
    ~DomNode();
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
