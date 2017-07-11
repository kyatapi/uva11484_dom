#pragma once
#include <memory>
#include <sstream>
#include <iostream>

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
    DomNode() : m_value(""), m_parent(nullptr), m_first_child(nullptr) { cout << "DomNode()" << this << "\n"; }
    DomNode(const string& value) : m_value(value), m_parent(nullptr), m_first_child(nullptr) { cout << "DomNode()" << this << "\n"; }
    ~DomNode() { cout << "~DomNode()" << this << "\n"; }

    const string& value() const { return m_value; }
    const shared_ptr<DomNode>& parent() const { return m_parent; }
    shared_ptr<DomNode>& parent() { return m_parent; }
    const shared_ptr<DomNode>& first_child() const { return m_first_child; }
    shared_ptr<DomNode>& first_child() { return m_first_child; }
    void set_parent(const shared_ptr<DomNode>& node);
    void add_child(const shared_ptr<DomNode>& node);
private:
    string m_value;
    shared_ptr<DomNode> m_parent;
    shared_ptr<DomNode> m_first_child;
};

class DomTree {
public:
    DomTree() : m_root(nullptr) {}
    ~DomTree() {}

    shared_ptr<const DomNode> root() const { return m_root; }
    friend istream & operator >> (std::istream &is, DomTree &rhs);
private:
    shared_ptr<DomNode> m_root;
}; 
