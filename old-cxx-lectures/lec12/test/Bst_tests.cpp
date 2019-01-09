#include "Bst_set.h"

#include <UnitTest++/UnitTest++.h>
#include <sstream>

TEST(Empty)
{
    Bst_set set;
    CHECK(set.empty());
    CHECK_EQUAL(0, set.size());
}

TEST(ContainsEmpty)
{
    Bst_set set;
    CHECK(!set.contains(5));
}

TEST(Insert)
{
    Bst_set set;
    set.insert(2);
    set.insert(4);
    set.insert(6);
    CHECK_EQUAL(3, set.size());
}

TEST(Debug1)
{
    Bst_set set;
    set.insert(4);
    set.insert(2);
    set.insert(6);

    std::ostringstream o;
    o << set;
    CHECK_EQUAL("((. 2 .) 4 (. 6 .))", o.str());
}

TEST(Debug2)
{
    Bst_set set;
    set.insert(2);
    set.insert(4);
    set.insert(6);

    std::ostringstream o;
    o << set;
    CHECK_EQUAL("(. 2 (. 4 (. 6 .)))", o.str());
}

TEST(InsertContains)
{
    Bst_set set;
    set.insert(2);
    set.insert(4);
    set.insert(6);

    CHECK(!set.contains(1));
    CHECK(set.contains(2));
    CHECK(!set.contains(3));
    CHECK(set.contains(4));
    CHECK(!set.contains(5));
    CHECK(set.contains(6));
    CHECK(!set.contains(7));
}

TEST(Reinsert)
{
    Bst_set set;

    set.insert(3);
    CHECK_EQUAL(1, set.size());

    set.insert(4);
    CHECK_EQUAL(2, set.size());

    set.insert(4);
    CHECK_EQUAL(2, set.size());

    set.insert(5);
    CHECK_EQUAL(3, set.size());

    set.insert(3);
    CHECK_EQUAL(3, set.size());
}

TEST(InitializerList)
{
    Bst_set set{2, 4, 6, 8};

    CHECK(!set.contains(1));
    CHECK(set.contains(2));
    CHECK(!set.contains(3));
    CHECK(set.contains(4));
    CHECK(!set.contains(5));
    CHECK(set.contains(6));
    CHECK(!set.contains(7));
    CHECK(set.contains(8));
    CHECK(!set.contains(9));

    Bst_set set2{4, 2, 1, 3, 6, 5, 7};

    CHECK(!set.contains(1));
    CHECK(set.contains(2));
    CHECK(!set.contains(3));
    CHECK(set.contains(4));
    CHECK(!set.contains(5));
    CHECK(set.contains(6));
    CHECK(!set.contains(7));
    CHECK(set.contains(8));
    CHECK(!set.contains(9));
}

TEST(Remove)
{
    for (int i = 0; i < 9; ++i) {
        Bst_set set{4, 2, 1, 3, 6, 5, 7};
        set.remove(i);

        for (int j = 1; j < 8; ++j) {
            CHECK_EQUAL(i != j, set.contains(j));
        }
    }
}

//TEST(DebugInteractive)
//{
//    std::cout << "Enter elements:\n> ";
//    std::string line;
//    if (! getline(std::cin, line)) {
//        throw std::runtime_error("could not getline");
//    }
//
//    std::istringstream input(line);
//    int n;
//    Bst_set set;
//    while (input >> n) set.insert(n);
//
//    std::cout << set;
//    std::cout << '\n';
//}
