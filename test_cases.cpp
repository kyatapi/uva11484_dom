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

TEST(ReadTree, HandleChildren) {
    istringstream iss("<node value='level0'>\n<node value='level1'>\n<node value='level2'>\n</node>\n</node>\n</node>");
    DomTree tree;
    iss >> tree;

    ASSERT_NE(tree.root(), nullptr);
    ASSERT_EQ(tree.root()->value(), "level0");
    ASSERT_EQ(tree.root()->first_child()->value(), "level1");
    ASSERT_EQ(tree.root()->first_child()->first_child()->value(), "level2");
}