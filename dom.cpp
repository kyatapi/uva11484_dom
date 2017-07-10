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
    if (is >> tag) {
        rhs.m_root = make_shared<DomNode>(tag.value());
    }
    return is;
};

int main(int argc, char **argv) {
    run_test(argc, argv);

    return 0;
}