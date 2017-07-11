#include  "dom.h"

#ifndef ONLINE_JUDGE
#include "test_cases.h"
extern void run_test(int argc, char **argv);
#else
inline void run_test(int argc, char **argv) {}
#endif // !ONLINE_JUDGE

using namespace std;

istream & operator >> (std::istream &is, DomTag &rhs) {
    string line = "";
    getline(is, line);
    size_t tag_start = line.find("<");
    if (tag_start != string::npos && tag_start + 1 < line.length()) {
        rhs.m_opening = (line[tag_start + 1] != '/');
        size_t value_start = line.find("value=", tag_start);
        if(value_start != string::npos) {
            value_start += 7;
            size_t value_end = line.find('\'', value_start);
            rhs.m_value = line.substr(value_start, value_end - value_start);
        }
    }
    return is;
}

istream & operator >> (std::istream &is, DomTree &rhs) {
    DomTag tag;
    shared_ptr<DomNode> root = make_shared<DomNode>();
    shared_ptr<DomNode> parent = root;
    shared_ptr<DomNode> current = nullptr;
    while (is >> tag) {
        if (tag.is_opening()) {
            current = make_shared<DomNode>(tag.value());
            parent->add_child(current);
            current->set_parent(parent);
            parent = current;
        }
        else {
            if (current != nullptr) current = current->parent();
            if (parent != nullptr) parent = parent->parent();
        }
    }
    rhs.m_root = root->first_child();
    if(rhs.m_root != nullptr) rhs.m_root->set_parent(nullptr);
    return is;
};

void DomNode::set_parent(const shared_ptr<DomNode>& node) {
    m_parent = node;
}

void DomNode::add_child(const shared_ptr<DomNode>& node) {
    m_first_child = node;
}

int main(int argc, char **argv) {
    run_test(argc, argv);

    return 0;
}