#include  "dom.h"

#ifndef ONLINE_JUDGE
#include "test_cases.h"
extern void run_test(int argc, char **argv);
#else
inline void run_test(int argc, char **argv) {}
#endif // !ONLINE_JUDGE

std::istream & operator >> (std::istream &is, DomTree &rhs)
{
    return is;
};

int main(int argc, char **argv) {
    run_test(argc, argv);

    return 0;
}