#include <sstream>
#include "test_cases.h"
#include "dom.h"

using namespace std;

TEST(ReadTag, HandleOpening) {
    istringstream iss("<node value='test'>");
    DomTag tag;
    iss >> tag;

    ASSERT_EQ(tag.is_opening(), true);
    ASSERT_EQ(tag.value(), "test");
}

TEST(ReadTag, HandleEnding) {
    istringstream iss("</node>");
    DomTag tag;
    iss >> tag;

    ASSERT_EQ(tag.is_opening(), false);
}

TEST(ReadTree, HandleEmptyDocument) {
    istringstream iss("");
    DomTree tree;
    iss >> tree;

    ASSERT_EQ(tree.root(), nullptr);
}

TEST(ReadTree, HandleOnlyRoot) {
    istringstream iss("<node value='root'>\n</node>");
    DomTree tree;
    iss >> tree;

    ASSERT_NE(tree.root(), nullptr);
    ASSERT_EQ(tree.root()->value(), "root");
}