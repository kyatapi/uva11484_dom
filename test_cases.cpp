#include <sstream>
#include "test_cases.h"
#include "dom.h"

using namespace std;

class DomTree;

TEST(ReadTree, HandleEmptyDocument) {
    istringstream iss("");
    DomTree tree;
    iss >> tree;

    ASSERT_EQ(tree.root(), nullptr);
}