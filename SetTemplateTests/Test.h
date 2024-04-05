#pragma once
#include "gtest/gtest.h"
#include "Template.h"

TEST(SetTest, AddTest) {
    Set<int> set;
    set.add(5);
    EXPECT_EQ(set.getSize(), 1);
    EXPECT_TRUE(set.contains(5));
}

TEST(SetTest, DefaultConstructorTest) {
    Set<int> set;
    EXPECT_EQ(set.getSize(), 0);
}

TEST(SetTest, CopyConstructorTest) {
    Set<int> set;
    set.add(1);
    set.add(2);
    Set<int> copiedSet(set);
    EXPECT_EQ(copiedSet.getSize(), set.getSize());
    EXPECT_TRUE(copiedSet.contains(1));
    EXPECT_TRUE(copiedSet.contains(2));
}

TEST(SetTest, AssignmentOperatorTest) {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    Set<int> set2;
    set2 = set1;
    EXPECT_EQ(set2.getSize(), set1.getSize());
    EXPECT_TRUE(set2.contains(1));
    EXPECT_TRUE(set2.contains(2));
}

TEST(SetTest, RemoveTest) {
    Set<int> set;
    set.add(5);
    set.remove(5);
    EXPECT_EQ(set.getSize(), 0);
    EXPECT_FALSE(set.contains(5));
}

TEST(SetTest, IntersectTest) {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    Set<int> set2;
    set2.add(2);
    set2.add(3);
    Set<int> result = set1.intersect(set2);
    EXPECT_EQ(result.getSize(), 1);
    EXPECT_TRUE(result.contains(2));
}

TEST(SetTest, DiffTest) {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    Set<int> set2;
    set2.add(2);
    set2.add(3);
    Set<int> result = set1.diff(set2);
    EXPECT_EQ(result.getSize(), 1);
    EXPECT_TRUE(result.contains(1));
}

TEST(SetTest, SymDiffTest) {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    Set<int> set2;
    set2.add(2);
    set2.add(3);
    Set<int> result = set1.sym_diff(set2);
    EXPECT_EQ(result.getSize(), 2);
    EXPECT_TRUE(result.contains(1));
    EXPECT_TRUE(result.contains(3));
}

TEST(SetTest, PrintTest) {
    Set<int> set;
    set.add(1);
    set.add(2);
    set.add(3);

    testing::internal::CaptureStdout();
    set.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");
}

TEST(SetTest, GetSizeTest) {
    Set<int> set;
    set.add(1);
    set.add(2);
    EXPECT_EQ(set.getSize(), 2);
}
