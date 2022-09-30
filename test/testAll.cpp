#include <gtest/gtest.h>
#include "testNode.cpp"
#include "testTrunk.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}